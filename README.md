# Distributed_Randomization_WirelessHART

Distributed schedule randomization implementation on the GISOO simulator (https://github.com/araujokth/kth-gisoo). The codes for the implementation is available in CodedKFSP folder. It contains the physical models and the controllers in Simulink Release 13 and the wirelessHART network in the Cooja simulator. I used Simulink in Matlab Release 13 as GISOO executable was written on a Real Time package which got renamed from Matlab Release 14 onwards. Hence for this setup I used GISOO, Matlab Release 13, Cooja and TinyOS to generate the executable for the TelosB motes. The results generated under different scenarios (with and without randomization, with and without period adaptation, with interference and period adaptation) are all available in the Results Folder. 

More details about the implementation are available in "Online Distributed Schedule Randomization to Mitigate Timing Attacks in Industrial Control Systems". Link to the paper : https://dl.acm.org/doi/10.1145/3624584

Theoretical Results with two, three and four clusters are given in Cluster_2, Cluster_3, Cluster_4 folders respectively.
