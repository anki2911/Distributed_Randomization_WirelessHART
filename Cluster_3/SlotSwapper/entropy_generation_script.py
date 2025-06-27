import sys
import os

for i in range(100):
    os.system("python SlotSwapper.py ../Util_75/Flow_4_1.txt ../Util_75/SlotSwapper/Sched_1_" + str(i+1) + ".txt ../Util_75/SlotSwapper_Entropy/Entropy_1_" + str(i+1) + ".txt ../Util_75/SlotSwapper_Entropy/entropy_out_1_" + str(i+1) + ".txt")
    
