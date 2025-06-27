import library_functions
#from igraph import *
import math
import sys
import time

def main():
    b = sys.argv[1]
    Big_Cluster = []
    
    CLUSTER = []
 
    num_of_cluster = int(sys.argv[2])
    num_of_keys = int(sys.argv[3])
    
    #Prob dist
    d = sys.argv[4]
    #Entropy 
    e = sys.argv[5]
   
    f = sys.argv[6]
    
    

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
        
      
    #for i in range(c1):
    #    x = library_functions.random.randint(1,len(p1))
    #    y = library_functions.random.randint(1,len(p1))
    #    C_Keys[0].append(p1[x-1])
    #    C_Keys[1].append(p1[y-1])
    #    x1 = p1[x-1]
    #    y1 = p1[y-1]
    #    p1.remove(x1)
    #    if x1 != y1:
    #        p1.remove(y1)
            
    #for i in range(c2):
    #    x = library_functions.random.randint(1,len(p2))
    #    y = library_functions.random.randint(1,len(p2))
    #    C_Keys[0].append(p2[x-1])
    #    C_Keys[1].append(p2[y-1])
    #    x2 = p2[x-1]
    #    y2 = p2[y-1]
    #    p2.remove(x2)
    #    if x2 != y2:
    #        p2.remove(y2)
            
            
    #for i in range(c3):
    #    x = library_functions.random.randint(1,len(p3))
    #    y = library_functions.random.randint(1,len(p3))
    #    C_Keys[0].append(p3[x-1])
    #    C_Keys[1].append(p3[y-1])
    #    x3 = p3[x-1]
    #    y3 = p3[y-1]
    #    p3.remove(x3)
    #    if x3 != y3:
    #        p3.remove(y3)
        
       
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
        f3 = open("../Util_" + str(f) + "/DistSlotShuffler/Sched_1_" + str(c) + ".txt","r")
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
    num_of_exp = 1
    
    select = 0
    no = 0
    #prev_ent = 0
    Ent= 0
    Flow_Generated_list = []
    Schedule_Generated_list = []
    while (no < num_of_exp):
        #print no
        #prev_ent = Ent
        select = (select + 1)%num_of_cluster
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
        
        #print(time.time())
        #print(time.clock())
       
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
        print(time.time())
        #print(time.clock())

        count1 = 0
        Schedule_Generated_list.append(S)
        Flow_Generated_list.append(F_Seq)
        #Base_Schedule_list.append(S)
        #Base_Flow_list.append(F_Seq) 
        for j in range(hyperperiod):
            if Flow_Generated_list[no][j] != "-":
                #Prob[j][int(Base_Flow_list[i][j])-1] += 1
                Prob[j][int(Flow_Generated_list[no][j])-1] += 1
            else:
                Prob[j][len(FLOW)] += 1
        
        no += 1
        
        #if prev_ent > 0:
        #    if abs((prev_ent - Ent)/prev_ent) < 0.0001:
        #        temp = no
        #        no = num_of_exp               
        
             
    #if temp == 0:
    #    temp = num_of_exp
    
    
    #string = str(e)+"no.txt"
    f4 = open(str(d),"w")   
    f5 = open(str(e),"w")  
    #f6 = open(string,"w")   
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
          
    #for j in range(hyperperiod):
        #for k in range(len(FLOW)+1):
    #    for k in range(len(FLOW)+1):
    #        if Prob[j][k] > 0:
    #            Ent = Ent - ((Prob[j][k]*1.0)/((temp)))* math.log((Prob[j][k]*1.0)/((temp)),2) 
                #print Prob[j][k]*1.0/num_of_exp
    #            f4.write(str((Prob[j][k]*1.0/((temp)))))
    #        else:
    #            f4.write(str(0))
    #        f4.write("\t")
    #    f4.write("\n")
    #print Ent
    
    #f5.write(str(Ent)) 
    #f6.write(str(temp))              
                    
    
    
    
if __name__ == '__main__':
    main()
