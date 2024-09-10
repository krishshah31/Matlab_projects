Jb = 0.5         %Jb=0.5kg*m^2
mf=0.1           %mf=0.1kg
h=0.1            %h=10cm
g=9.81           %g=9.81m*s^-2
Jconst=mf*h^2+Jb;

%code for getting values from worksapce

alpha=out.alpha;
alpha_dot=out.alpha_dot;
xf=out.xf;
xf_dot=out.xf_dot;

%code for ploting and placement of graphs 

figure=nexttile;
plot (alpha)
title('alpha')
xlabel('time in seconds')
ylabel('angle in radian')
legend('alpha')

figure=nexttile;
plot (alpha_dot)
title('alpha dot')
xlabel('time in seconds')
ylabel('angle in radian')
legend('alpha dot')

figure=nexttile;
plot(xf_dot)
title('xf dot')
xlabel('time in seconds')
ylabel('distance in meters')
legend('xf dot')

figure=nexttile;
plot(xf)
title('xf')
xlabel('time in seconds')
ylabel('distance in meters')
legend('xf')





