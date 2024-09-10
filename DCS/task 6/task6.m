Jb = 0.5;        %Jb=0.5kg*m^2
mf = 0.1;        %mf=0.1kg
h=0.1;           %h=10cm
g=9.81 ;         %g=9.81m*s^-2
Jconst=mf*h^2+Jb;

%state-space system
%state vector x=[alpha_dot; alpha;xf_dot;xf]

A=[0,mf*g*h/Jconst,0,-mf*g/Jconst; 1,0,0,0; 0,-g,0,0; 0,0,1,0];
B=[1/Jconst;0;0;0];
C=[0,0,0,1];
D=0;

sys_poles = eig(A);

S = [B A*B A^2*B A^3*B];  %controllability matrix
rank(S) % check for full rank of controllability
S_inv = inv(S);   %inverse of controllability matrix
qT = S_inv (4,:); %taking last row of controllablity

p1=-1; %setting all poles to -1
p2=-1;
p3=-1;
p4=-1;

alpha = poly([p1 p2 p3 p4]); %converting roots to polynomial
%applying akermanns formula
kT = qT*(alpha(5)*eye(4)+alpha(4)*A+alpha(3)*A^2+alpha(2)*A^3+A^4); 
P=1/(C*inv(B*kT-A)*B); % pre amplifier

Api= [A [0;0;0;0]; -C 0];
Bpi= [B; 0];
Cpi= [0 0 0 1 0];
Dpi= [0;0;0;0;0];
%Contobility matrix
Spi= [Bpi Api*Bpi Api^2*Bpi Api^3*Bpi Api^4*Bpi];
%Inverse of controbility matrix
Spi_inv = inv(Spi);
%last Row of controliblity matrix
qT_pi = Spi_inv(5,1:5);
p1= -1;
p2= -1;
p3= -1;
p4= -1;
p5= -1;
%convert roots to polynomial
alpha_pi= poly([p1 p2 p3 p4 p5]);
%apply akkermann formula
kpi = qT_pi*(alpha_pi(6)*eye(5) + alpha_pi(5)*Api + alpha_pi(4)*Api^2 + alpha_pi(3)*Api^3 + alpha_pi(2)*Api^4 + Api^5);
PI = -kpi(5);
%State Feedback Value
kT_pi = kpi(1:4)-P*C;

fs = 800;    %Sampling rate (800Hz)
Ts= 125e-4;   %Sampling time

sys = ss(A, B, C, 0);
sys_d = c2d(sys, Ts);    %Continuous to Discrete state space
[Ad4, Bd4, Cd4, Dd4]= ssdata(sys_d);

%applying akkerman to new discrete system
kTpi=acker(Ad4,Bd4,[exp(-1*Ts) exp(-1*Ts) exp(-1*Ts) exp(-1*Ts)]); 
P=1/(Cd4*inv(eye(4)-(Ad4-Bd4*kTpi))*Bd4);

sys = ss(Api, Bpi, Cpi, 0);
sys_d = c2d(sys, Ts);    %Continuous to Discrete state space
[Ad, Bd, Cd, Dd]= ssdata(sys_d);

Spi_d = [Bd Ad*Bd Ad^2*Bd Ad^3*Bd Ad^4*Bd];  %Controlability matrix
Spi_inv_d= inv(Spi_d);    %Inverse of Controlability matrix
qT_pi_d = Spi_inv_d (5, 1:5);    % Last row of Inverse Controlability
sys_pi =tf(1,poly([-1,-1,-1,-1,-1]));
desys_pi = c2d(sys_pi, Ts);
[n_alpha,d_alpha]=tfdata(desys_pi,'v'); %Geting Transfer function data

%Applying Ackerman's formula

kpi_d = qT_pi_d * (d_alpha(6)*eye(5)+d_alpha(5)*Ad+d_alpha(4)*Ad^2+d_alpha(3)*Ad^3+d_alpha(2)*Ad^4+Ad^5);
PI_d = -kpi_d(5);    %Integral gain
kT_pi_d = kpi_d(1:4)-P*C;    %State feedback value

linear_displacement=out.linear;
non_linear_displacement=out.non_linear;


plot (linear_displacement)
title('Linear Displacement')
xlabel('Time in Seconds')
ylabel('Displacement in meters')
legend('position linear','refrence position','disturbance torque')
grid on 
grid minor

plot (non_linear_displacement)
title('Non-Linear Displacement')
xlabel('Time in Seconds')
ylabel('Displacement in meters')
legend('position linear','refrence position','disturbance torque')
grid on 
grid minor

