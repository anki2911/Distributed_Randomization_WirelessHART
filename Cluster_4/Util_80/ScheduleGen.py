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
    
    num_of_flows = 6
    hyperperiod = 60
    for i in range(100):
        Schedule = []
        for t in range(hyperperiod):
            Schedule.append((0,0,0))
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
                        #print(Schedule[p][2])
                        #print(Schedule)
                        if Schedule[p][2] == 0:
                            if p not in random_number:
                                random_number.append(p)
                                l = l + 1
                    
                    #print(random_number)
                    random_number.sort()
                    for l in range(len(FLOW[k].flow)):
                        r = random_number[l]
                        Schedule[r] = ((FLOW[k].flow[l][0],FLOW[k].flow[l][1],k+1))
        
        f = open("SlotSwapper/Sched_1_"+str(i+1)+".txt",'w')
        for t in range(hyperperiod):
            if Schedule[t][2] == 0:
                f.write("- - -\n")
            else:
                f.write(str(Schedule[t][0])+' '+str(Schedule[t][1])+' '+str(Schedule[t][2])+'\n')
        f.close()
        print(i)
       
        
    
if __name__ == '__main__':
    main()
