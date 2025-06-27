# Distributed_Randomization_WirelessHART

Distributed schedule randomization implementation on the GISOO simulator (https://github.com/araujokth/kth-gisoo). The codes for the implementation is available in CodedKFSP folder. It contains the physical models and the controllers in Simulink in Matlab Release 13 and the wirelessHART network in the Cooja simulator. The codes for the WirelessHART motes are written in TinyOS. I used Simulink in Matlab Release 13 as all the subsequent versions of Matlab did not support the toolchain. This is mainly because the GISOO executable was written on a Real Time package which got renamed from Matlab Release 14 onwards. Hence for this setup I used GISOO, Matlab Release 13, Cooja and TinyOS. The results generated under different scenarios (with and without randomization, with and without period adaptation, with and without interference trigerred after period adaptation) are all available in the Results Folder. 

More details about the implementation are available in our publication 
 Ankita Samaddar, Arvind Easwaran, "Online Distributed Schedule Randomization with Period Adaptation to Mitigate Timing Attacks in Industrial Control Systems", ACM Transactions on Embedded Computing Systems (TECS), Volume 22, Issue 6, Pages 1-39, November 2023 (ACM Digital Library). Link to the paper : https://dl.acm.org/doi/10.1145/3624584

Theoretical Results on comparison of the distributed schedule randomization with the centralized schedule randomization with two, three and four clusters are given in Cluster_2, Cluster_3, Cluster_4 folders respectively.
