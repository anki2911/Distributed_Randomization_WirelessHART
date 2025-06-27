import sys
import os

for i in range(100):
    os.system("python Brute_Force_Entropy.py ../Util_73.3/Flow_4_1.txt  ../Util_73.3/SlotSwapper/Sched_1_" + str(i+1) + ".txt  ../Util_73.3/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    os.system("python Brute_Force_Entropy.py ../Util_80/Flow_4_1.txt  ../Util_80/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_80/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    os.system("python Brute_Force_Entropy.py ../Util_83.3/Flow_4_1.txt  ../Util_83.3/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_83.3/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    os.system("python Brute_Force_Entropy.py ../Util_90/Flow_4_1.txt  ../Util_90/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_90/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    os.system("python Brute_Force_Entropy.py ../Util_93.3/Flow_4_1.txt  ../Util_93.3/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_93.3/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    
    os.system("python Brute_Force_Entropy.py ../Util_33.3/Flow_4_1.txt  ../Util_33.3/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_33.3/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    os.system("python Brute_Force_Entropy.py ../Util_50/Flow_4_1.txt  ../Util_50/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_50/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    os.system("python Brute_Force_Entropy.py ../Util_66.6/Flow_4_1.txt  ../Util_66.6/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_66.6/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")
    #os.system("python Brute_Force_Entropy.py ../Util_75/Flow_4_1.txt  ../Util_75/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_75/BruteForce_Entropy/Prob_1_" + str(i+1) + ".txt")

    print(i)
    
