Jb = 0.5;        %Jb=0.5kg*m^2
mf = 0.1;           %mf=0.1kg
h=0.1;            %h=10cm
g=9.81 ;          %g=9.81m*s^-2
Jconst=mf*h^2+Jb;

%state-space system
%state vector x=[alpha_dot; alpha;xf_dot;xf]

A=[0,mf*g*h/Jconst,0,-mf*g/Jconst; 1,0,0,0; 0,-g,0,0; 0,0,1,0];
B=[1/Jconst;0;0;0];
C=[0,0,0,1];
D=0;

Jb = 0.5;        %Jb=0.5kg*m^2
mf = 0.1;           %mf=0.1kg
h=0.1;            %h=10cm
g=9.81 ;          %g=9.81m*s^-2
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
kpi = qT_pi*[alpha_pi(6)*eye(5) + alpha_pi(5)*Api + alpha_pi(4)*Api^2 + alpha_pi(3)*Api^3 + alpha_pi(2)*Api^4 + Api^5];
PI = -kpi(5);
%State Feedback Value
kT_pi = kpi(1:4)-P*C;

% code for ploting and graph placement
linear_displacement=out.linear1;

plot (linear_displacement)
title('Linear Displacement')
xlabel('Time in Seconds')
ylabel('Displacement in meters')
legend('position linear','refrence position','disturbance torque')
grid on 
grid minor






