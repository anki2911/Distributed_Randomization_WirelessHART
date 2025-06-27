import sys
#sys.path.append ('../../SingleChannel/')
import library_functions
import library_multi_channel
import random
from igraph import *
from tqdm import tqdm
import math


def main():
    FLOW = []
    deadline_list = []
    #f2 = open("D1/Flow_set_1_1.txt","r")
    f2 = open(str(sys.argv[1]),"r")
    i = 0
    for l in f2:
        l = l.strip()
        for words in l:
            words = l.split()
        #print words
        if words[0][0] == "F":
            FLOW.append(library_functions.Flow(0,[],0))
    f2.close()
    #counter = 0
    #print len(FLOW)
    i = -1
    #f3 = open("D1/Flow_set_1_1.txt","r")
    f3 = open(str(sys.argv[1]),"r")
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
    Prob = []
    hyperperiod = library_functions.find_LCM(FLOW)
    #possibilities = math.factorial(hyperperiod*num_of_chan)/math.factorial(count)
    c = 0
    #denom = math.factorial(hyperperiod)
    for i in range(len(FLOW)):
        num_of_inst = (hyperperiod/FLOW[i].deadline)*len(FLOW[i].flow)
        #denom = denom*1.0/math.factorial(num_of_inst)
        c = c + num_of_inst
    #print c
    #denom = denom*1.0/math.factorial((hyperperiod-c))
    #possibilities = math.factorial(c+count)
    #print "denom" + str(denom)
    #for i in range(len(FLOW)):
        #possibilities = possibilities*1.0/math.factorial(len(FLOW[i].flow))
        
    #print "Possibilities " + str(possibilities)  
    #raw_input()  
    count = 0
    f3 = open(str(sys.argv[2]),"r")
    #f3 = open("D1/Sched_1_1.txt","r")
    for lines in f3:
        lines = lines.strip()
        lines = lines.split(" ")
        print lines
        if lines[0] == "-":
            count += 1
    print "Count " + str(count)  
    print "C " + str(c) 
    print "Engaged " + str(hyperperiod - c)
    for i in tqdm(range(hyperperiod)):
        for k in range(len(FLOW)):   
            num_of_inst = (hyperperiod/FLOW[k].deadline)*len(FLOW[k].flow)
            #num_of_inst = len(FLOW[k].flow)
            #num_of_inst = len(FLOW[k].flow)
            #print len(FLOW[k].flow)
            Pr = num_of_inst*1.0/hyperperiod
            Prob.append(Pr)
            
            #print Pr
        Prob.append((hyperperiod-c)*1.0/(hyperperiod))
    #print count*1.0/hyperperiod
    #raw_input()
    Ent = 0.0
    out = open(str(sys.argv[3]),"w")
    for i in tqdm(range(hyperperiod)):
        for k in range(len(FLOW)+1):
            if Prob[k] > 0:
                #print Prob[k]
                
                Ent = Ent - Prob[k]*math.log(Prob[k]*1.0,2)
            out.write(str(Prob[k]))
            out.write("\t")
        out.write("\n")
        #out.write("\n")
    out.close()
    #print Ent
    #print Ent
if __name__ == '__main__':
    main()
