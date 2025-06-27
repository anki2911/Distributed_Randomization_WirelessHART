figure(1)
DIC1 = DIC(month==1);
DIC2 = DIC(month==2);
DIC3 = DIC(month==3);
DIC4 = DIC(month==4);
DIC5 = DIC(month==5);
DIC6 = DIC(month==6);
DIC7 = DIC(month==7);
DIC8 = DIC(month==8);
DIC9 = DIC(month==9);
DIC10 = DIC(month==10);
DIC11 = DIC(month==11);
DIC12 = DIC(month==12);
g = [ones(size(DIC1));2*ones(size(DIC2));3*ones(size(DIC3));4*ones(size(DIC4));5*ones(size(DIC5));...
    6*ones(size(DIC6));7*ones(size(DIC7));8*ones(size(DIC8));...
    9*ones(size(DIC9));10*ones(size(DIC10));11*ones(size(DIC11));12*ones(size(DIC12))];
Months = {'Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'};
x = [DIC1;DIC2;DIC3;DIC4;DIC5;DIC6;DIC7;DIC8;DIC9;DIC10;DIC11;DIC12];
h = boxplot(x,g,'Labels',Months);
ylabel('DIC (\mumol/kg)')
color = [([0.55 0.71 0]); ([0.55 0.71 0]); ([1 0.2 0]); ([0.4 0.4 0.5]);([0.4 0.4 0.5]); ([1 0.2 0]);([0.6 0.8 1]); ([0.6 0.8 1]);([0.6 0.8 1]);( [0.78 0.26 0.46]);([0.78 0.26 0.46]); ([0.55 0.71 0])]; 
h = findobj(gca,'Tag','Box'); 
for j=1:length(h) 
patch(get(h(j),'XData'),get(h(j),'YData'),color(j),'FaceAlpha',.5);
end 