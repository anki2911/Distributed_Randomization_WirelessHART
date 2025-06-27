import library_functions
#from igraph import *
import math
import sys
import random

def main():
    #Flow set file
    b = sys.argv[1]
    
    CLUSTER = []

    #number of schedules to generate
    num_schedule = int(sys.argv[2])    

    FLOW = []
    deadline_list = []
    
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
    

    num_of_cluster = 4
    num_of_flows = 6
    hyperperiod = 60
    for i in range(100):
        Schedule = []
        Cluster = [] 
        Empty = []
        for t in range(num_of_cluster):
            Cluster.append([])
        
        util_1 = 0
        util_2 = 0
        util_3 = 0
        util_4 = 0
        for t in range(hyperperiod):
            Schedule.append((0,0,0,0))
            Empty.append(t)

        for k in range(num_of_flows):
            for j in range(hyperperiod):
                if (j+1)%FLOW[k].deadline == 0:
                    release_time = (j+1)-FLOW[k].deadline
                    deadline = j
                    #print(release_time)
                    #print(deadline)
                    random_number = []
                    l = 0
                    while l < len(FLOW[k].flow):
                        p = random.randint(release_time,deadline)
                        #print(p)
                        #print(Schedule[p][2])
                        #print(Schedule)
                        if Schedule[p][2] == 0:
                            if p not in random_number:
                                random_number.append(p)
                                Empty.remove(p)
                                l = l + 1
                    
                    #print(random_number)
                    random_number.sort()
                    for l in range(len(FLOW[k].flow)):
                        r = random_number[l]
                        if FLOW[k].deadline == 10:
                            Schedule[r] = ((FLOW[k].flow[l][0],FLOW[k].flow[l][1],k+1,1))
                            Cluster[0].append(r)
                            util_1 = util_1 + 1
                        elif FLOW[k].deadline == 15:
                            Schedule[r] = ((FLOW[k].flow[l][0],FLOW[k].flow[l][1],k+1,2))
                            Cluster[1].append(r)
                            util_2 = util_2 + 1
                        elif FLOW[k].deadline == 20:
                            Schedule[r] = ((FLOW[k].flow[l][0],FLOW[k].flow[l][1],k+1,3))
                            Cluster[2].append(r)
                            util_3 = util_3 + 1
                        elif FLOW[k].deadline == 30:
                            Schedule[r] = ((FLOW[k].flow[l][0],FLOW[k].flow[l][1],k+1,4))
                            Cluster[3].append(r)
                            util_4 = util_4 + 1
        
        
        empty_1 = int(util_1*(hyperperiod - util_1 - util_2 - util_3 - util_4)/(util_1 + util_2 + util_3 + util_4))
        empty_2 = int(util_2*(hyperperiod - util_1 - util_2 - util_3 - util_4)/(util_1 + util_2 + util_3 + util_4))
        empty_3 = int(util_3*(hyperperiod - util_1 - util_2 - util_3 - util_4)/(util_1 + util_2 + util_3 + util_4))
        empty_4 = int(hyperperiod - (util_1 + util_2 + util_3 + util_4 + empty_1 + empty_2 + empty_3))
        
        t = 0
        while t < empty_1:
            #print(Schedule)
            p = random.randint(0,len(Empty)-1)
            #print(p)
            #print(Empty)
            content = Empty[p]
            #print(content)
            Schedule[content] = ((0,0,0,1))
            Empty.remove(content)
            t = t + 1

        t = 0
        while t < empty_2:
            p = random.randint(0,len(Empty)-1)
            #print(p)
            content = Empty[p]
            Schedule[content] = ((0,0,0,2))
            Empty.remove(content)
            t = t + 1

        t = 0
        while t < empty_3:
            #print(Schedule)
            p = random.randint(0,len(Empty)-1)
            #print(p)
            #print(Empty)
            content = Empty[p]
            #print(content)
            Schedule[content] = ((0,0,0,3))
            Empty.remove(content)
            t = t + 1

        t = 0
        while t < empty_4:
            #print(Schedule)
            p = random.randint(0,len(Empty)-1)
            #print(p)
            #print(Empty)
            content = Empty[p]
            #print(content)
            Schedule[content] = ((0,0,0,4))
            Empty.remove(content)
            t = t + 1
        #print(Schedule)               

                     

        f = open("DistSlotShuffler/Sched_1_"+str(i+1)+".txt",'w')
        for t in range(hyperperiod):
            if Schedule[t][2] == 0:
                f.write('- - - '+str(Schedule[t][3])+' \n')
            else:
                f.write(str(Schedule[t][0])+' '+str(Schedule[t][1])+' '+str(Schedule[t][2])+' '+str(Schedule[t][3])+'\n')
        f.close()
        print(i)
       
        
    
if __name__ == '__main__':
    main()
