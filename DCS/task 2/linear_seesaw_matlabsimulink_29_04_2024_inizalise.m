Jb = 0.5;        %Jb=0.5kg*m^2
mf = 0.1;           %mf=0.1kg
h=0.1;            %h=10cm
g=9.81 ;          %g=9.81m*s^-2
Jconst=mf*h^2+Jb;

A=[0,mf*g*h/Jconst,0,-mf*g/Jconst; 1,0,0,0; 0,-g,0,0; 0,0,1,0];
B=[1/Jconst;0;0;0];
C=[0,0,0,1];
D=0;

alpha_compare=out.alpha_compare;
alpha_dot_compare=out.alpha_dot_compare;
xf_compare=out.xf_compare; 
xf_dot_compare=out.xf_dot_compare;

%code for ploting and placement of graphs 

figure=nexttile;

plot (alpha_dot_compare)
title('Angular Velocity Comparision')
xlabel('Time in Seconds')
ylabel('Angular velocity')
legend('refrence torque in Nm','alpha dot non-linear in Rad/s','alpha dot linear in Rad/s')
grid on
grid minor

figure=nexttile;

plot (alpha_compare)
title('Angle Comparision')
xlabel('Time in Seconds')
ylabel('Angle in Radian')
legend('refrence torque in Nm)','alpha non-linear in Rad','alpha linear in Rad')
grid on
grid minor

figure=nexttile;

plot(xf_compare)
plot(xf_dot_compare)
title('Displacement Comparision')
xlabel('Time in seconds')
ylabel('Displacement in Meters')
legend('refrence torque in Nm','xf in m','xf linear in m')
grid on
grid minor

figure=nexttile;

plot(xf_dot_compare)
title('Velocity Comparision')
xlabel('Time in seconds')
ylabel('Velocity in m/s')
legend('refrence torque in Nm','xf dot in m','xf dot linear in m')
grid minor
grid on
