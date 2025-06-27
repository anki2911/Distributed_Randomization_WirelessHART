import library_functions
#from igraph import *
import math
import sys



def main():
    #a = sys.argv[1]
    b = sys.argv[1]
    c = sys.argv[2]
    d = sys.argv[3]
    e = sys.argv[4]
    #Read Graph instance from file
    #Node = []
    #Edge = []
    #temp = 0
    #g = Graph(directed=True)
    #f1 = open("Graph.txt","r")
   
    #f1 = open(str(a),"r")
    #counter = 0
    #for lines in f1:
    #    lines = lines.strip()
    #    for words in lines:
    #        words = lines.split()
            #print words
            #print "Hello"
    #    if counter == 0:
    #        num_of_nodes = int(words[0])
            #print num_of_nodes
            #g.add_vertices(num_of_nodes) 
    #        for i in range(num_of_nodes):
    #            Node.append(int(i+1))  
    #    else:
            #print words[0]
            #print words[1]
    #        p = (int(words[0]),int(words[1]))
    #        Edge.append(p) 
            #g.add_edges([p])
    #    counter += 1
    
    FLOW = []
    deadline_list = []
    #f2 = open("Flow.txt","r")
    f2 = open(str(b),"r")
    i = 0
    for l in f2:
        l = l.strip()
        for words in l:
            words = l.split()
        if words[0][0] == "F":
            FLOW.append(library_functions.Flow(0,[],0))
    f2.close()
    
    i = -1
    #f3 = open("Flow.txt","r")
    f3 = open(str(b),"r")
    for lines in f3:
        lines = lines.strip()
        #print counter
        if lines[0][0] == "F":
            fid = lines
            counter = 0
            i += 1
        elif counter == 1:
            deadline = int(lines)
            FLOW[i].deadline = deadline
        else:
            lines = lines.split(" ")
            FLOW[i].flow.append((int(lines[0]),int(lines[1])))
        counter += 1    
        
    #Implementation of Slot Shuffler
    #hyperperiod = library_functions.find_LCM(FLOW)
    hyperperiod = 60
    #print hyperperiod
    num_of_chan = 1
    #Communication in the schedule
    Slots = []
    #Flow in the schedule
    Flows_Seq = []
    Link = []
    F = []
    #Flow Sequence
    #Flow_chart = []
    #for i in range(len(FLOW)):
    #    Flow_chart.append([])
    #Base Schedule
    #f3 = open("Schedule_Default.txt","r")
    f3 = open(str(c),"r")
    for lines in f3:
        lines = lines.split()
        n1 = lines[0]
        n2 = lines[1]
        if n1 == "-" and n2 == "-":
            Slots.append((int(-1),int(-1)))
            Flows_Seq.append("-")
        else:
            Slots.append((n1,n2))
            Flows_Seq.append(lines[2])
            #Flow_chart[int(lines[2]) - 1].append((n1,n2))
            #print int(lines[2])
            #print FLOW[int(lines[2])-1].deadline
            #FLOW[int(lines[2])-1].exec_time += 1
        #print lines              
    
    Base_Schedule_list = []
    Base_Schedule_list.append(Slots)
    Base_Flow_list = []
    Base_Flow_list.append(Flows_Seq)
    #Dist = []
    #Dist.append(1)
    L_act = []  
    Prob = []
    for j in range(hyperperiod):
        L = []
        for k in range(len(FLOW)+1):
            L.append(0)
        Prob.append(L)
           
    #num_of_exp = 10000
    num_of_exp = 100
    select = 0
    no = 0
    prev_ent = 0
    Ent= 0
    while (no < num_of_exp):
        #print no
        prev_ent = Ent
        S = []
        F_Seq = []
        for index in range(len(Base_Schedule_list[select])):
            S.append((0,0))
            F_Seq.append(0)
        S = list(S)
        for index in range(len(Base_Schedule_list[select])):
            S[index] = Base_Schedule_list[select][index]
            F_Seq[index] = Base_Flow_list[select][index]
          
        S = tuple(S)
        #print S
        #print F_Seq
        tick = 1
        while tick <= hyperperiod:
            for i in range(len(FLOW)):
                if (tick%FLOW[i].deadline == 0 and tick > 0):
                    lb = tick - FLOW[i].deadline
                    ub = tick - 1
                    #print lb
                    #print ub
                    #print i
                    Shuffle_slots = []
                    curr_flow = i+1
                    #print curr_flow
                    #keeps track of ordering in a window
                    flow_ordering = []
                    for j in range(len(FLOW)):
                        flow_ordering.append([])
                    t = lb
                    while (t <= ub):
                        f = F_Seq[t]
                       #print "T " + str(t)
                        if f != "-":
                            flow_ordering[int(f)-1].append(S[t])
                        t += 1 
                    #print flow_ordering
                    Shuffle_slots = library_functions.find_shuffling_slots(curr_flow,F_Seq,lb,ub,Shuffle_slots)
                    #print Shuffle_slots
                    for k in range(len(Shuffle_slots)):
                        available_slots = []
                        pos = Shuffle_slots[k]
                        curr_slot = Shuffle_slots[k]
                        available_slots = library_functions.find_available_slots(i,pos,lb,ub,F_Seq,available_slots)
                        #print available_slots
                        cand = []
                        for num in range(len(available_slots)):
                            flag = library_functions.check_available(FLOW,curr_slot,num,F_Seq,available_slots,lb,ub)
                            if flag == 1:
                                cand.append(num)
                               # print num
                        if len(cand) > 0:
                            #print cand
                            random_slot = library_functions.random.randint(0,len(cand)-1) 
                            slot_to_be_swapped = lb + cand[random_slot]
                            S,F_Seq = library_functions.Shuffler(curr_slot,slot_to_be_swapped,S,F_Seq)  
                            S,F_Seq = library_functions.Order_list(len(FLOW),lb,ub,S,F_Seq,flow_ordering)
                            del available_slots
                    del flow_ordering
                        
            tick += 1
        #print S
        #print F_Seq
        
        select += 1
        count1 = 0
        Base_Schedule_list.append(S)
        Base_Flow_list.append(F_Seq) 
        #for j in range(hyperperiod):
        #    if Base_Flow_list[no][j] != "-":
                #Prob[j][int(Base_Flow_list[i][j])-1] += 1
        #        Prob[j][int(Base_Flow_list[no][j])-1] += 1
        #    else:
        #        Prob[j][len(FLOW)] += 1
        
        no += 1
        
        
    Select_24_schedules = []
    Select_24_FSeq = []
    
    for i in range(24):
        num = library_functions.random.randint(1,len(Base_Schedule_list))
        Select_24_schedules.append(Base_Schedule_list[num - 1])
        Select_24_FSeq.append(Base_Flow_list[num - 1])
        S = Base_Schedule_list[num - 1]
        F = Base_Flow_list[num - 1]
        Base_Schedule_list.remove(S)
        Base_Flow_list.remove(F)
    
    for i in range(100):
        num = library_functions.random.randint(1,len(Select_24_schedules))
        for j in range(hyperperiod):
            if Select_24_FSeq[num-1][j] != "-":
                #Prob[j][int(Base_Flow_list[i][j])-1] += 1
                Prob[j][int(Select_24_FSeq[num-1][j])-1] += 1
            else:
                Prob[j][len(FLOW)] += 1
            
        
    f4 = open(str(d),"w")   
    f5 = open(str(e),"w")
    Ent = 0  
    for j in range(hyperperiod):
        for k in range(len(FLOW)+1):
            #for k in range(len(FLOW)+1):
            if Prob[j][k] > 0:
                Ent = Ent - ((Prob[j][k]*1.0)/(100))* math.log((Prob[j][k]*1.0)/(100),2) 
                f4.write(str((Prob[j][k]*1.0)/(100)))
            else:
                f4.write(str(0))
            f4.write("\t")
        f4.write("\n")
    #print Ent
    f5.write(str(Ent))
    
                #print Prob[j][k]*1.0/100
               
        #print Ent
        #if prev_ent > 0:
            #if abs((prev_ent - Ent)/prev_ent) < 0.0001:
                #temp = no
                #no = num_of_exp               
        
             
    #if temp == 0:
        #temp = num_of_exp
    #string = str(e)
    #f4 = open(str(d),"w")   
    #f5 = open(str(e),"w")  
    #f6 = open(string,"w")     
    #for j in range(hyperperiod):
        #for k in range(len(FLOW)+1):
        #for k in range(len(FLOW)+1):
            #if Prob[j][k] > 0:
                #Ent = Ent - ((Prob[j][k]*1.0)/((temp)))* math.log((Prob[j][k]*1.0)/((temp)),2) 
                #print Prob[j][k]*1.0/num_of_exp
                #f4.write(str((Prob[j][k]*1.0/((temp)))))
            #else:
                #f4.write(str(0))
            #f4.write("\t")
        #f4.write("\n")
    #print Ent
    
    #f5.write(str(Ent)) 
    #f6.write(str(temp))          
    
if __name__=='__main__':
    main()
