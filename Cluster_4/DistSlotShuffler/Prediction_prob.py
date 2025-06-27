import library_functions
#from igraph import *
import math
import sys

def main():
    b = sys.argv[1]
    Big_Cluster = []
    
    CLUSTER = []
 
    num_of_cluster = int(sys.argv[2])
    num_of_keys = int(sys.argv[3])
    
    #Prob dist
    #d = sys.argv[4]
    #Entropy 
    #e = sys.argv[5]
   
    util = sys.argv[4]
    
    #g = sys.argv[5]

    FLOW = []
    deadline_list = []
    
    
    C_Keys = []
    
    for i in range(num_of_cluster):
        Big_Cluster.append([])
        
    for i in range(num_of_cluster):
        for j in range(4):
            Big_Cluster[i].append([])
            #C_Keys.append([])
    
    C_Period = []
    C_Period.append(10)
    C_Period.append(15)
    C_Period.append(20)
    C_Period.append(30)
    #Key Generation
    import itertools
    p1 = list(itertools.permutations([1, 2, 3]))
    p2 = list(itertools.permutations([1, 2, 3, 4]))
    p3 = list(itertools.permutations([1, 2, 3, 4, 5]))
    p4 = list(itertools.permutations([1, 2, 3, 4, 5, 6]))
    p5 = list(itertools.permutations([1, 2, 3, 4, 5, 6, 7]))
    p6 = list(itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8]))
    p7 = list(itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8, 9]))
    p8 = list(itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    
    
    P = []
    for i in range(len(p1)):
        P.append(p1[i])
        
    for i in range(len(p2)):
        P.append(p2[i])
    
    for i in range(len(p3)):
        P.append(p3[i])   
        
    for i in range(len(p4)):
        P.append(p4[i]) 
    
    for i in range(len(p5)):
        P.append(p5[i]) 
    
    for i in range(len(p6)):
        P.append(p6[i]) 
    
    for i in range(len(p7)):
        P.append(p7[i])   
    
    for i in range(len(p8)):
        P.append(p8[i]) 

    for i in range(num_of_keys):
        x = library_functions.random.randint(1,len(P))
        x_key = P[x-1]
        C_Keys.append(x_key)
        P.remove(x_key)    
       
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
    
    Link = []
    F = []
    
    Base_Schedule_list = []
    Base_Flow_list = []
    for i in range(num_of_cluster):
        count = 0
        #Communication in the schedule
        Slots = []
        #Flow in the schedule
        Flows_Seq = []
        c = library_functions.random.randint(1,100)
        f3 = open("../Util_" + str(util) + "/DistSlotShuffler/Sched_1_" + str(c) + ".txt","r")
        for lines in f3:
            lines = lines.split()
            n1 = lines[0]
            n2 = lines[1]
            n3 = lines[3]
            if n1 == "-" and n2 == "-":
                Slots.append((int(-1),int(-1)))
                Flows_Seq.append("-")
                index = int(lines[3])
                Big_Cluster[i][index-1].append(count)
            else:
                Slots.append((n1,n2))
                Flows_Seq.append(lines[2])
                index = int(lines[3])
                Big_Cluster[i][index-1].append(count)
            count += 1
        Base_Schedule_list.append(Slots)
        Base_Flow_list.append(Flows_Seq)
    
    
        
            #Flow_chart[int(lines[2]) - 1].append((n1,n2))
            #print int(lines[2])
            #print FLOW[int(lines[2])-1].deadline
            #FLOW[int(lines[2])-1].exec_time += 1
        #print lines              
    #print CLUSTER
    
    
    
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
    #prev_ent = 0
    Ent= 0
    Flow_Generated_list = []
    Schedule_Generated_list = []
    while (no < num_of_exp):
        #print no
        #prev_ent = Ent
        #select = (select + 1)%num_of_cluster
        select = library_functions.random.randint(0,num_of_cluster-1)
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
    
        tick = 1
        while tick <= hyperperiod:
            for i in range(4):
                if (tick%C_Period[i] == 0 and tick > 0):
                    lb = tick - C_Period[i]
                    ub = tick - 1
                    #print lb
                    #print ub
                    #print i  
                    chunks1 = []
                    chunks2 = []
                    start = lb
                    num = 0
                    #Appending the slots belonging to each cluster in chunks1 and chunks2 respectively
                    while (start <= ub):
                        if start in Big_Cluster[select][i]:
                            chunks1.append(S[start])
                            chunks2.append(F_Seq[start])  
                            num += 1 
                        start += 1
                    
                    #Permutation
                    ptr = 0
                    f = 0
                    #print chunks1
                    #print chunks2
                    remain = len(chunks2)
                    while ptr < len(chunks1):
                        key_index = library_functions.random.randint(0,len(P)-1)
                        key = P[key_index]
                        chunks3 = []
                        chunks4 = []
                        for k in range(len(key)):
                            chunks3.append((0,0))
                            chunks4.append(0)
                        start = ptr
                        end = start + len(key) - 1
                        remain = remain - len(key) 
                        #print "Key " + str(key)
                        #print start
                        #print end
                        #print "Remaining " + str(remain)
                        if remain < 0:
                            q = -(remain)
                            for k in range(q):
                                chunks1 = list(chunks1)
                                chunks1.append((-100,-100))
                                chunks2.append((-100))
                                chunks1 = tuple(chunks1)
                                f += 1
                        #print chunks1
                        for k in range(len(key)):
                            chunks1 = list(chunks1)
                            chunks3 = list(chunks3)
                            chunks3[k] = chunks1[ptr + key[k] - 1]
                            chunks3 = tuple(chunks3)
                            chunks1 = tuple(chunks1) 
                            chunks4[k] = chunks2[ptr + key[k] - 1]
                            
                        for k in range(len(key)):
                            chunks1 = list(chunks1)
                            chunks3 = list(chunks3)
                            chunks1[ptr + k] = chunks3[k]
                            chunks2[ptr + k] = chunks4[k]
                            chunks3 = tuple(chunks3)
                            chunks1 = tuple(chunks1) 
                        #print chunks1
                        
                        if f > 0:
                            for k in range(f):
                                chunks1 = list(chunks1)
                                chunks1.remove((-100,-100))
                                chunks1 = tuple(chunks1)
                                chunks2.remove(-100)
                            
                        ptr = ptr + len(key)
                        #print ptr
                                               
                    start = lb
                    S = list(S)
                    k = 0
                    #Appending the slots belonging to each cluster in chunks1 and chunks2 respectively
                    while (start <= ub):
                        if start in Big_Cluster[select][i]:
                            S[start] = chunks1[k]
                            F_Seq[start] = chunks2[k]
                            k += 1  
                        start += 1
                    S = tuple(S)        
            tick += 1
        #print S
        #print F_Seq
        #t = raw_input()
        #select += 1
        count1 = 0
        Schedule_Generated_list.append(S)
        Flow_Generated_list.append(F_Seq)
        #Base_Schedule_list.append(S)
        #Base_Flow_list.append(F_Seq) 
        
        no += 1
        
    Links = []    
    Predict = []
    PP = []
    for i in range(100):
        Predict.append([])
        Links.append([])
        PP.append([])
    for i in range(100):
        for j in range(60):
            Predict[i].append([])
            Links[i].append([])
            PP[i].append([])
    for i in range(100):
        for j in range(60):
            for k in range(7):
                Predict[i][j].append(0)
                Links[i][j].append(Schedule_Generated_list[i][j])
                PP[i][j].append(0)       
        
    for i in range(100):
        for j in range(60):
            if i > 0:
                if Flow_Generated_list[i][j] != "-":
                    s = int(Flow_Generated_list[i][j])
                    #print s
                    Predict[i][j][s - 1] += 1
                     
    f7 = open("../Util_" + str(util) + "/PP_Slot_" + str(util) + "_" + str(num_of_cluster) + "_" + str(num_of_keys) + ".txt","w")           
    for i in range(100):
        for j in range(60):
            for k in range(7):
                sum = 0
                if i > 0:
                    for l in range(i-1):
                        if Schedule_Generated_list[i][j][0] != -1 and Schedule_Generated_list[i][j][1] != -1 and Schedule_Generated_list[i][j][0] == Schedule_Generated_list[l][j][0] and Schedule_Generated_list[i][j][1] == Schedule_Generated_list[l][j][1]:
                            if Predict[i][j][k] > 0 and Predict[i][j][k] == Predict[l][j][k]:
                                sum += 1
                        #print sum
                    PP[i][j][k] = sum*1.0/(i+1)
            m = max(PP[i][j])
            #print m
            f7.write(str(m))
            f7.write("\n")
                
    #print Predict            
    #print PP            
    
if __name__ == '__main__':
    main()
