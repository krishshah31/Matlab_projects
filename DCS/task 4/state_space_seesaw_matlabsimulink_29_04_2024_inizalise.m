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
% Ct = C(4,:);
P=1/(C*inv(B*kT-A)*B); % pre amplifier


linear_displacement=out.linear;
non_linear_displacement=out.non_linear;

% %code for ploting and placement of graphs 

figure=nexttile;

plot (linear_displacement)
title('Linear Displacement')
xlabel('Time in Seconds')
ylabel('Displacement in meters')
legend('position linear','refrence position','disturbance torque')
grid on 
grid minor

figure=nexttile;

plot (non_linear_displacement)
title('Non Liear Displacement')
xlabel('Time in Seconds')
ylabel('Displacement in meters')
legend('position linear','refrence position','disturbance torque')
grid on 
grid minor

