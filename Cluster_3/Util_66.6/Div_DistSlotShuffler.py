import sys
import math
import os


def main():
    
    hyperperiod = 60
    a = sys.argv[1]
    b = sys.argv[2]
    f3 = open("Divergence_" + str(a) + "_" + str(b) + ".txt","w")
    
    for i in range(0,100):
        BF = []
        Alg = []
    
        f1 = open("BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt",'r')
        for l in f1:
            l = l.split()
            temp1 = []
            for words in l:
                temp1.append(words)
            BF.append(temp1)
        #print(len(BF))
        
        f2 = open("DistslotShuffler_Entropy/" + str(sys.argv[1]) + "_" + str(sys.argv[2]) + "/Prob_1_" + str(i+1) + ".txt",'r')
        for l in f2:
            l = l.split()
            temp2 = []
            for words in l:
                temp2.append(words)
            Alg.append(temp2)
        #print(Alg)   
        
        div = 0
        for j in range(0,60):
            for k in range(0,5):
                #print(BF[j][k])
                #print(Alg[j][k])
                if float(Alg[j][k]) != 0.0 and float(BF[j][k]) != 0.0:
                    div = div + float(Alg[j][k])/(100) * math.log(((float(Alg[j][k])/100)/(float(BF[j][k])/100)),2)
                
        f3.write(str(div))
        f3.write("\n")
        print(div)
        del(BF)
        del(Alg)
    f3.close()


    





if __name__ == '__main__':
    main()