F1 = fopen('Divergence_SlotSwapper_80.txt','r');
Data_1 = fscanf(F1,'%f');
F2 = fopen('Divergence_2_7.txt','r');
Data_2 = fscanf(F2,'%f');
F3 = fopen('Divergence_12_6.txt','r');
Data_3 = fscanf(F3,'%f');
F4 = fopen('Divergence_22_5.txt','r');
Data_4 = fscanf(F4,'%f');
F5 = fopen('Divergence_32_4.txt','r');
Data_5 = fscanf(F5,'%f');
F6 = fopen('Divergence_42_3.txt','r');
Data_6 = fscanf(F6,'%f');
F7 = fopen('Divergence_52_2.txt','r');
Data_7 = fscanf(F7,'%f');
F8 = fopen('Divergence_62_1.txt','r');
Data_8 = fscanf(F8,'%f');
fclose(F1);
fclose(F2);
fclose(F3);
fclose(F4);
fclose(F5);
fclose(F6);
fclose(F7);
fclose(F8);

color = [([1 0 0]); ([0 0 1]); ([0 0 1]); ([0 0 1]);([0 0 1]); ([0 0 1]);([0 0 1]); ([0 0 1])]; 
Data = [Data_1;Data_2;Data_3;Data_4;Data_5;Data_6;Data_7;Data_8];
%g = [repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_1)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_2)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_3)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_4)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_5)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_6)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_7)),1);repmat(cellstr(sprintf('24 schedules \n SlotSwapper')),ones(size(Data_8)),1)];
%g = [repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_1), 1); repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_2), 1); repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_3), 1); repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_4), 1); repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_5), 1); repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_6), 1); repmat(cellstr(sprintf('First Line G1\nSecond Line G1')), length(Data_7), 1); repmat(cellstr(sprintf('First Line G2\nSecond Line G2')), length(Data_8), 1)]; 
g = [ones(size(Data_1)); 2*ones(size(Data_2)); 3*ones(size(Data_3));4*ones(size(Data_4));5*ones(size(Data_5));6*ones(size(Data_6));7*ones(size(Data_7));8*ones(size(Data_8))];
Values = {'24 schedules','2:7 Split','12:6 Split','22:5 Split', '32:4 Split','42:3 Split','52:2 Split','62:1 Split'};

%Values = {(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper']),(['24 schedules';'SlotSwapper'])};


B = boxplot(Data,g,'Labels',Values,'colors',color,'symbol','','LabelOrientation','horizontal');
%legend('Group A','Group B','Group C')


%title('Upper-bound K-L divergence at 33.3% slot utilization','fontweight','bold','fontsize',20);
ylabel('Upper-bound K-L dvergence','fontweight','bold','fontsize',20);
xlabel('Maximum memory consumption','fontweight','bold','fontsize',20);
%ticks = ['SlotSwapper(24 Schedules)','2 keys,7 BaseClusters', '12 keys,6 BaseClusters', '22 keys,4 BaseClusters','32 keys, 3 BaseClusters','42 keys, 4 BaseClusters','52 keys, 5 BaseClusters', '62 keys, 1 BaseCluster'];
%ht = text(5, 0.5, {'{\color{red} o } Red', '{\color{blue} o } Blue', '{\color{black} o } Black'}, 'EdgeColor', 'k');
box_vars = findobj(gca,'Tag','Box');
%disp (box_vars);
hLegend = legend(box_vars([1,8]), {'\bf{DistSlotShuffler}','\bf{SlotSwapper}'});

 set(findobj(gca,'Type','text'),'FontSize',18,'fontWeight','bold'); % to set Xaxis
 set(gca,'FontSize',18,'Fontweight','bold') % to set Yaxis
 for ih=1:8
    set(B(ih,:),'LineWidth',3.0);
 end

%hLegend = legend(findobj(gca,'Tag','Box'), {'Group A','Group B'});
%xlabel({'First line';'Second line'});
%set(gca,'XTickLabel',['1  ';'100']);
%set(gca, 'XTick',1:8,'XTickLabel',{'SlotSwapper\\newline24','DistSlotShuffler (2-7)','DistSlotShuffler (12-6)','DistSlotShuffler(22-5)','DistSlotShuffler (32-4)','DistSlotShuffler (42-3)','DistSlotShuffler (52-2)','DistSlotShuffler (62-1)';'24 schedules','2 keys 7 cluster allocations','12 keys 6 cluster allocations','22 keys 5 cluster allocations','32 keys 4 cluster allocations','42 keys 3 cluster allocations','52 keys 2 clustr allocations', '62 keys 1 cluster allocation'});