#include "Timer.h"
#include "Permute.h"

module RelayC @safe() 
{
  
    uses interface Leds;
    uses interface Boot;
  
    uses interface AMSend;
    uses interface Receive as R_A;
	uses interface Receive as R_B;
    uses interface Timer<TMilli> as Timer1;
    //uses interface Timer<TMilli> as Timer2;
    //uses interface Timer<TMilli> as Timer3;
    //uses interface Timer<TMilli> as Timer4;
    uses interface SplitControl as AMControl;
    uses interface Packet;

}
implementation 
{
    static int32_t val1;
	static int32_t val2;

	static int32_t Buffer1[10];
	static int32_t Buffer2[10];
	static int16_t index;
	static bool lowpowersignal;

	static Control_Loop_t Cntl[10];
    static Flow_t F[10];
    //Cluster Declaration
    static Cluster_t C[10];

    int unused_slots;
    int total_hops = 0;

    message_t packet_s;
    message_t packet_r;
	message_t packet_rb;
    
    message_t* recvBuf;
    message_t* sendBuf;

    radio_count_msg_t* rcm;
    radio_count_msg_t* rcv;
	radio_count_msg_t* rcv_b;

    uint16_t timeslot = 0;
	uint16_t key_select;
    
    static slot_info_t BaseSchedule[65]; 

    task void initializeFlow();
    task void assignFlowstoSlots();
    task void initializeSchedule();
	task void PermutateCipher();
	task void updateSchedule();
	task void initializeCluster();

    event void Boot.booted() 
    {
		key_select = 5;
		lowpowersignal = FALSE;
        call AMControl.start();
    }

    event void AMControl.startDone(error_t err) 
    {
        if (err == SUCCESS) 
        {
			post initializeCluster();
            post initializeFlow();
            post assignFlowstoSlots();
            post initializeSchedule();
			
            call Timer1.startPeriodic(15);
        }
        else 
        {
            call AMControl.start();
        }
    }

    event void AMControl.stopDone(error_t err) 
    {
        // do nothing
    }

    task void initializeFlow()
    {
		int i;
		//FLOW 1
        F[0].flow_id = 1;
		F[0].cntl_ID = 1;
		F[0].cluster_id = 1;
        F[0].n_hops = 3;
        F[0].period = 10;
		F[0].n_inst = (HYPERPERIOD-1)/F[0].period;
        F[0].route[0][0] = 6;
        F[0].route[0][1] = 15;		
		F[0].route[1][0] = 15;
        F[0].route[1][1] = 16;
        F[0].route[2][0] = 16;
        F[0].route[2][1] = 7;

        //FLOW 2
        F[1].flow_id = 2;
		F[1].cntl_ID = 2;
		F[1].cluster_id = 1;
        F[1].n_hops = 1;
        F[1].period = 10;
		F[1].n_inst = (HYPERPERIOD-1)/F[1].period;
        F[1].route[0][0] = 6;
        F[1].route[0][1] = 8;
        
		/*F[1].route[1][0] = 5;
        F[1].route[1][1] = 8;
        F[1].route[2][0] = 8;
        F[1].route[2][1] = 9;*/

        //FLOW 3
        F[2].flow_id = 3;
		F[2].cntl_ID = 3;
		F[2].cluster_id = 2;
        F[2].n_hops = 3;
        F[2].period = 15;
		F[2].n_inst = (HYPERPERIOD-1)/F[2].period;
        F[2].route[0][0] = 6;
        F[2].route[0][1] = 17;
        F[2].route[1][0] = 17;
        F[2].route[1][1] = 18;
        F[2].route[2][0] = 18;
        F[2].route[2][1] = 9;

        //FLOW 4
        F[3].flow_id = 4;
		F[3].cntl_ID = 4;
        F[3].cluster_id = 2;
        F[3].n_hops = 2;
        F[3].period = 15;
		F[3].n_inst = (HYPERPERIOD-1)/F[3].period;
        F[3].route[0][0] = 6;
        F[3].route[0][1] = 18;
		F[3].route[1][0] = 18;
        F[3].route[1][1] = 10;
        
		/*F[3].route[2][0] = 8;
        F[3].route[2][1] = 9;*/

		atomic
		{
			for (i = 0;i < 10;i++)
			{
				Buffer1[i] = 0;
				Buffer2[i] = 0;
			}
		}
    }
	
	task void initializeCluster()
    {
        int i;
    
		C[0].cl_id = 1;
        C[0].period = 10;
				
		/*C[0].num_of_keys = 24;
		C[0].key_length[0] = 4;
		C[0].key[0][0] = 3;
		C[0].key[0][1] = 2;
		C[0].key[0][2] = 1;
		C[0].key[0][3] = 4;
		C[0].key_length[1] = 4;
		C[0].key[1][0] = 4;
		C[0].key[1][1] = 2;
		C[0].key[1][2] = 1;
		C[0].key[1][3] = 3;
		C[0].key_length[2] = 4;
		C[0].key[2][0] = 4;
		C[0].key[2][1] = 1;
		C[0].key[2][2] = 3;
		C[0].key[2][3] = 2;
		C[0].key_length[3] = 4;
		C[0].key[3][0] = 1;
		C[0].key[3][1] = 3;
		C[0].key[3][2] = 4;
		C[0].key[3][3] = 2;
		C[0].key_length[4] = 4;
		C[0].key[4][0] = 2;
		C[0].key[4][1] = 4;
		C[0].key[4][2] = 1;
		C[0].key[4][3] = 3;
		C[0].key_length[5] = 4;
		C[0].key[5][0] = 2;
		C[0].key[5][1] = 1;
		C[0].key[5][2] = 3;
		C[0].key[5][3] = 4;
		C[0].key_length[6] = 4;
		C[0].key[6][0] = 4;
		C[0].key[6][1] = 1;
		C[0].key[6][2] = 2;
		C[0].key[6][3] = 3;
		C[0].key_length[7] = 4;
		C[0].key[7][0] = 1;
		C[0].key[7][1] = 2;
		C[0].key[7][2] = 3;
		C[0].key[7][3] = 4;
		C[0].key_length[8] = 4;
		C[0].key[8][0] = 1;
		C[0].key[8][1] = 2;
		C[0].key[8][2] = 4;
		C[0].key[8][3] = 3;
		C[0].key_length[9] = 4;
		C[0].key[9][0] = 4;
		C[0].key[9][1] = 3;
		C[0].key[9][2] = 1;
		C[0].key[9][3] = 2;
		C[0].key_length[10] = 4;
		C[0].key[10][0] = 1;
		C[0].key[10][1] = 3;
		C[0].key[10][2] = 2;
		C[0].key[10][3] = 4;
		C[0].key_length[11] = 4;
		C[0].key[11][0] = 3;
		C[0].key[11][1] = 1;
		C[0].key[11][2] = 2;
		C[0].key[11][3] = 4;
		C[0].key_length[12] = 4;
		C[0].key[12][0] = 2;
		C[0].key[12][1] = 1;
		C[0].key[12][2] = 4;
		C[0].key[12][3] = 3;
		C[0].key_length[13] = 4;
		C[0].key[13][0] = 2;
		C[0].key[13][1] = 3;
		C[0].key[13][2] = 1;
		C[0].key[13][3] = 4;
		C[0].key_length[14] = 4;
		C[0].key[14][0] = 4;
		C[0].key[14][1] = 3;
		C[0].key[14][2] = 2;
		C[0].key[14][3] = 1;
		C[0].key_length[15] = 4;
		C[0].key[15][0] = 3;
		C[0].key[15][1] = 4;
		C[0].key[15][2] = 2;
		C[0].key[15][3] = 1;
		C[0].key_length[16] = 4;
		C[0].key[16][0] = 1;
		C[0].key[16][1] = 4;
		C[0].key[16][2] = 3;
		C[0].key[16][3] = 2;
		C[0].key_length[17] = 4;
		C[0].key[17][0] = 4;
		C[0].key[17][1] = 2;
		C[0].key[17][2] = 3;
		C[0].key[17][3] = 1;
		C[0].key_length[18] = 4;
		C[0].key[18][0] = 1;
		C[0].key[18][1] = 4;
		C[0].key[18][2] = 2;
		C[0].key[18][3] = 3;
		C[0].key_length[19] = 4;
		C[0].key[19][0] = 3;
		C[0].key[19][1] = 4;
		C[0].key[19][2] = 1;
		C[0].key[19][3] = 2;
		C[0].key_length[20] = 4;
		C[0].key[20][0] = 2;
		C[0].key[20][1] = 3;
		C[0].key[20][2] = 4;
		C[0].key[20][3] = 1;
		C[0].key_length[21] = 4;
		C[0].key[21][0] = 2;
		C[0].key[21][1] = 4;
		C[0].key[21][2] = 3;
		C[0].key[21][3] = 1;
		C[0].key_length[22] = 4;
		C[0].key[22][0] = 3;
		C[0].key[22][1] = 2;
		C[0].key[22][2] = 4;
		C[0].key[22][3] = 1;
		C[0].key_length[23] = 4;
		C[0].key[23][0] = 3;
		C[0].key[23][1] = 1;
		C[0].key[23][2] = 4;
		C[0].key[23][3] = 2;*/
		
		//Variable length keys
		C[0].num_of_keys = 20;
		C[0].key_length[0] = 3;
		C[0].key[0][0] = 3;
		C[0].key[0][1] = 2;
		C[0].key[0][2] = 1;
		C[0].key_length[1] = 4;
		C[0].key[1][0] = 3;
		C[0].key[1][1] = 2;
		C[0].key[1][2] = 1;
		C[0].key[1][3] = 4;
		C[0].key_length[2] = 5;
		C[0].key[2][0] = 3;
		C[0].key[2][1] = 2;
		C[0].key[2][2] = 5;
		C[0].key[2][3] = 4;
		C[0].key[2][4] = 1;		
		C[0].key_length[3] = 4;
		C[0].key[3][0] = 1;
		C[0].key[3][1] = 3;
		C[0].key[3][2] = 4;
		C[0].key[3][3] = 2;
		C[0].key_length[4] = 5;
		C[0].key[4][0] = 5;
		C[0].key[4][1] = 4;
		C[0].key[4][2] = 3;
		C[0].key[4][3] = 2;
		C[0].key[4][4] = 1;
		C[0].key_length[5] = 3;
		C[0].key[5][0] = 1;
		C[0].key[5][1] = 3;
		C[0].key[5][2] = 2;
		C[0].key_length[6] = 5;
		C[0].key[6][0] = 4;
		C[0].key[6][1] = 5;
		C[0].key[6][2] = 1;
		C[0].key[6][3] = 3;
		C[0].key[6][4] = 2;
		C[0].key_length[7] = 5;
		C[0].key[7][0] = 2;
		C[0].key[7][1] = 4;
		C[0].key[7][2] = 5;
		C[0].key[7][3] = 1;
		C[0].key[7][4] = 3;
		C[0].key_length[8] = 5;
		C[0].key[8][0] = 2;
		C[0].key[8][1] = 1;
		C[0].key[8][2] = 4;
		C[0].key[8][3] = 5;
		C[0].key[8][4] = 3;
		C[0].key_length[9] = 5;
		C[0].key[9][0] = 4;
		C[0].key[9][1] = 1;
		C[0].key[9][2] = 3;
		C[0].key[9][3] = 5;
		C[0].key[9][4] = 2;
		C[0].key_length[10] = 3;
		C[0].key[10][0] = 3;
		C[0].key[10][1] = 1;
		C[0].key[10][2] = 2;
		C[0].key_length[11] = 5;
		C[0].key[11][0] = 4;
		C[0].key[11][1] = 3;
		C[0].key[11][2] = 2;
		C[0].key[11][3] = 5;
		C[0].key[11][4] = 1;
		C[0].key_length[12] = 5;
		C[0].key[12][0] = 3;
		C[0].key[12][1] = 5;
		C[0].key[12][2] = 1;
		C[0].key[12][3] = 4;
		C[0].key[12][4] = 2;
		C[0].key_length[13] = 4;
		C[0].key[13][0] = 4;
		C[0].key[13][1] = 3;
		C[0].key[13][2] = 1;
		C[0].key[13][3] = 2;
		C[0].key_length[14] = 4;
		C[0].key[14][0] = 3;
		C[0].key[14][1] = 1;
		C[0].key[14][2] = 4;
		C[0].key[14][3] = 2;
		C[0].key_length[15] = 4;
		C[0].key[15][0] = 1;
		C[0].key[15][1] = 4;
		C[0].key[15][2] = 2;
		C[0].key[15][3] = 3;
		C[0].key_length[16] = 5;
		C[0].key[16][0] = 5;
		C[0].key[16][1] = 1;
		C[0].key[16][2] = 3;
		C[0].key[16][3] = 2;
		C[0].key[16][4] = 4;
		C[0].key_length[17] = 4;
		C[0].key[17][0] = 3;
		C[0].key[17][1] = 4;
		C[0].key[17][2] = 2;
		C[0].key[17][3] = 1;
		C[0].key_length[18] = 4;
		C[0].key[18][0] = 2;
		C[0].key[18][1] = 3;
		C[0].key[18][2] = 4;
		C[0].key[18][3] = 1;
		C[0].key_length[19] = 4;
		C[0].key[19][0] = 3;
		C[0].key[19][1] = 1;
		C[0].key[19][2] = 4;
		C[0].key[19][3] = 2;
		
		C[1].cl_id = 2;
        C[1].period = 15;
		
		/*C[1].num_of_keys = 24;
		C[1].key_length[0] = 4;
		C[1].key[0][0] = 3;
		C[1].key[0][1] = 2;
		C[1].key[0][2] = 1;
		C[1].key[0][3] = 4;
		C[1].key_length[1] = 4;
		C[1].key[1][0] = 4;
		C[1].key[1][1] = 2;
		C[1].key[1][2] = 1;
		C[1].key[1][3] = 3;
		C[1].key_length[2] = 4;
		C[1].key[2][0] = 4;
		C[1].key[2][1] = 1;
		C[1].key[2][2] = 3;
		C[1].key[2][3] = 2;
		C[1].key_length[3] = 4;
		C[1].key[3][0] = 1;
		C[1].key[3][1] = 3;
		C[1].key[3][2] = 4;
		C[1].key[3][3] = 2;
		C[1].key_length[4] = 4;
		C[1].key[4][0] = 2;
		C[1].key[4][1] = 4;
		C[1].key[4][2] = 1;
		C[1].key[4][3] = 3;
		C[1].key_length[5] = 4;
		C[1].key[5][0] = 2;
		C[1].key[5][1] = 1;
		C[1].key[5][2] = 3;
		C[1].key[5][3] = 4;
		C[1].key_length[6] = 4;
		C[1].key[6][0] = 4;
		C[1].key[6][1] = 1;
		C[1].key[6][2] = 2;
		C[1].key[6][3] = 3;
		C[1].key_length[7] = 4;
		C[1].key[7][0] = 1;
		C[1].key[7][1] = 2;
		C[1].key[7][2] = 3;
		C[1].key[7][3] = 4;
		C[1].key_length[8] = 4;
		C[1].key[8][0] = 1;
		C[1].key[8][1] = 2;
		C[1].key[8][2] = 4;
		C[1].key[8][3] = 3;
		C[1].key_length[9] = 4;
		C[1].key[9][0] = 4;
		C[1].key[9][1] = 3;
		C[1].key[9][2] = 1;
		C[1].key[9][3] = 2;
		C[1].key_length[10] = 4;
		C[1].key[10][0] = 1;
		C[1].key[10][1] = 3;
		C[1].key[10][2] = 2;
		C[1].key[10][3] = 4;
		C[1].key_length[11] = 4;
		C[1].key[11][0] = 3;
		C[1].key[11][1] = 1;
		C[1].key[11][2] = 2;
		C[1].key[11][3] = 4;
		C[1].key_length[12] = 4;
		C[1].key[12][0] = 2;
		C[1].key[12][1] = 1;
		C[1].key[12][2] = 4;
		C[1].key[12][3] = 3;
		C[1].key_length[13] = 4;
		C[1].key[13][0] = 2;
		C[1].key[13][1] = 3;
		C[1].key[13][2] = 1;
		C[1].key[13][3] = 4;
		C[1].key_length[14] = 4;
		C[1].key[14][0] = 4;
		C[1].key[14][1] = 3;
		C[1].key[14][2] = 2;
		C[1].key[14][3] = 1;
		C[1].key_length[15] = 4;
		C[1].key[15][0] = 3;
		C[1].key[15][1] = 4;
		C[1].key[15][2] = 2;
		C[1].key[15][3] = 1;
		C[1].key_length[16] = 4;
		C[1].key[16][0] = 1;
		C[1].key[16][1] = 4;
		C[1].key[16][2] = 3;
		C[1].key[16][3] = 2;
		C[1].key_length[17] = 4;
		C[1].key[17][0] = 4;
		C[1].key[17][1] = 2;
		C[1].key[17][2] = 3;
		C[1].key[17][3] = 1;
		C[1].key_length[18] = 4;
		C[1].key[18][0] = 1;
		C[1].key[18][1] = 4;
		C[1].key[18][2] = 2;
		C[1].key[18][3] = 3;
		C[1].key_length[19] = 4;
		C[1].key[19][0] = 3;
		C[1].key[19][1] = 4;
		C[1].key[19][2] = 1;
		C[1].key[19][3] = 2;
		C[1].key_length[20] = 4;
		C[1].key[20][0] = 2;
		C[1].key[20][1] = 3;
		C[1].key[20][2] = 4;
		C[1].key[20][3] = 1;
		C[1].key_length[21] = 4;
		C[1].key[21][0] = 2;
		C[1].key[21][1] = 4;
		C[1].key[21][2] = 3;
		C[1].key[21][3] = 1;
		C[1].key_length[22] = 4;
		C[1].key[22][0] = 3;
		C[1].key[22][1] = 2;
		C[1].key[22][2] = 4;
		C[1].key[22][3] = 1;
		C[1].key_length[23] = 4;
		C[1].key[23][0] = 3;
		C[1].key[23][1] = 1;
		C[1].key[23][2] = 4;
		C[1].key[23][3] = 2;*/
		
		//Variable length keys
		C[1].num_of_keys = 20;
		C[1].key_length[0] = 3;
		C[1].key[0][0] = 3;
		C[1].key[0][1] = 2;
		C[1].key[0][2] = 1;
		C[1].key_length[1] = 4;
		C[1].key[1][0] = 3;
		C[1].key[1][1] = 2;
		C[1].key[1][2] = 1;
		C[1].key[1][3] = 4;
		C[1].key_length[2] = 5;
		C[1].key[2][0] = 3;
		C[1].key[2][1] = 2;
		C[1].key[2][2] = 5;
		C[1].key[2][3] = 4;
		C[1].key[2][4] = 1;		
		C[1].key_length[3] = 4;
		C[1].key[3][0] = 1;
		C[1].key[3][1] = 3;
		C[1].key[3][2] = 4;
		C[1].key[3][3] = 2;
		C[1].key_length[4] = 5;
		C[1].key[4][0] = 5;
		C[1].key[4][1] = 4;
		C[1].key[4][2] = 3;
		C[1].key[4][3] = 2;
		C[1].key[4][4] = 1;
		C[1].key_length[5] = 3;
		C[1].key[5][0] = 1;
		C[1].key[5][1] = 3;
		C[1].key[5][2] = 2;
		C[1].key_length[6] = 5;
		C[1].key[6][0] = 4;
		C[1].key[6][1] = 5;
		C[1].key[6][2] = 1;
		C[1].key[6][3] = 3;
		C[1].key[6][4] = 2;
		C[1].key_length[7] = 5;
		C[1].key[7][0] = 2;
		C[1].key[7][1] = 4;
		C[1].key[7][2] = 5;
		C[1].key[7][3] = 1;
		C[1].key[7][4] = 3;
		C[1].key_length[8] = 5;
		C[1].key[8][0] = 2;
		C[1].key[8][1] = 1;
		C[1].key[8][2] = 4;
		C[1].key[8][3] = 5;
		C[1].key[8][4] = 3;
		C[1].key_length[9] = 5;
		C[1].key[9][0] = 4;
		C[1].key[9][1] = 1;
		C[1].key[9][2] = 3;
		C[1].key[9][3] = 5;
		C[1].key[9][4] = 2;
		C[1].key_length[10] = 3;
		C[1].key[10][0] = 3;
		C[1].key[10][1] = 1;
		C[1].key[10][2] = 2;
		C[1].key_length[11] = 5;
		C[1].key[11][0] = 4;
		C[1].key[11][1] = 3;
		C[1].key[11][2] = 2;
		C[1].key[11][3] = 5;
		C[1].key[11][4] = 1;
		C[1].key_length[12] = 5;
		C[1].key[12][0] = 3;
		C[1].key[12][1] = 5;
		C[1].key[12][2] = 1;
		C[1].key[12][3] = 4;
		C[1].key[12][4] = 2;
		C[1].key_length[13] = 4;
		C[1].key[13][0] = 4;
		C[1].key[13][1] = 3;
		C[1].key[13][2] = 1;
		C[1].key[13][3] = 2;
		C[1].key_length[14] = 4;
		C[1].key[14][0] = 3;
		C[1].key[14][1] = 1;
		C[1].key[14][2] = 4;
		C[1].key[14][3] = 2;
		C[1].key_length[15] = 4;
		C[1].key[15][0] = 1;
		C[1].key[15][1] = 4;
		C[1].key[15][2] = 2;
		C[1].key[15][3] = 3;
		C[1].key_length[16] = 5;
		C[1].key[16][0] = 5;
		C[1].key[16][1] = 1;
		C[1].key[16][2] = 3;
		C[1].key[16][3] = 2;
		C[1].key[16][4] = 4;
		C[1].key_length[17] = 4;
		C[1].key[17][0] = 3;
		C[1].key[17][1] = 4;
		C[1].key[17][2] = 2;
		C[1].key[17][3] = 1;
		C[1].key_length[18] = 4;
		C[1].key[18][0] = 2;
		C[1].key[18][1] = 3;
		C[1].key[18][2] = 4;
		C[1].key[18][3] = 1;
		C[1].key_length[19] = 4;
		C[1].key[19][0] = 3;
		C[1].key[19][1] = 1;
		C[1].key[19][2] = 4;
		C[1].key[19][3] = 2;
		
        
        for (i = 0;i < HYPERPERIOD-1;i++)
        {
            C[0].slots[i] = -1;
            C[1].slots[i] = -1;
            BaseSchedule[i].s = -1;
            BaseSchedule[i].r = -1;
            BaseSchedule[i].fid = -1;
        }
    }
	
    task void assignFlowstoSlots()
    {
		Cntl[0].period = 10;
		Cntl[1].period = 10;
		Cntl[2].period = 15;
		Cntl[3].period = 15;
		
		Cntl[0].available_periods[0] = 10;
		Cntl[0].available_periods[1] = 20;
		Cntl[0].available_periods[2] = 30;
		Cntl[0].available_periods[3] = 60;
		Cntl[1].available_periods[0] = 10;
		Cntl[1].available_periods[1] = 20;
		Cntl[1].available_periods[2] = 60;
		Cntl[2].available_periods[0] = 15;
		Cntl[2].available_periods[1] = 30;
		Cntl[2].available_periods[2] = 60;
		Cntl[3].available_periods[0] = 15;
		Cntl[3].available_periods[1] = 30;
		Cntl[3].available_periods[2] = 60;
		
		C[0].period = 10;
		C[0].slots[0] = 1;
		C[0].slots[1] = 2;
		C[0].slots[2] = -1;
        C[0].slots[3] = -1;
        C[0].slots[4] = 1;
        C[0].slots[5] = 1;
        C[0].slots[6] = -1;
        C[0].slots[7] = -1;
        C[0].slots[8] = 0;
        C[0].slots[9] = 0;
        C[0].slots[10] = 1;
        C[0].slots[11] = 2;
		C[0].slots[12] = -1;
        C[0].slots[13] = -1;
        C[0].slots[14] = 1;
        C[0].slots[15] = -1;
		C[0].slots[16] = -1;
		C[0].slots[17] = 1;
		C[0].slots[18] = 0;
        C[0].slots[19] = 0;
        C[0].slots[20] = 1;
        C[0].slots[21] = 2;
        C[0].slots[22] = 1;
        C[0].slots[23] = -1;
        C[0].slots[24] = 1;
        C[0].slots[25] = 0;
        C[0].slots[26] = 0;
        C[0].slots[27] = -1;
		C[0].slots[28] = -1;
        C[0].slots[29] = -1;
        C[0].slots[30] = -1;
        C[0].slots[31] = -1;
		C[0].slots[32] = 1;
		C[0].slots[33] = 2;
		C[0].slots[34] = 1;
        C[0].slots[35] = -1;
        C[0].slots[36] = 1;
        C[0].slots[37] = 0;
        C[0].slots[38] = 0;
        C[0].slots[39] = -1;
        C[0].slots[40] = 1;
        C[0].slots[41] = 2;
        C[0].slots[42] = -1;
        C[0].slots[43] = 1;
		C[0].slots[44] = -1;
        C[0].slots[45] = -1;
        C[0].slots[46] = 1;
        C[0].slots[47] = 0;
		C[0].slots[48] = -1;
		C[0].slots[49] = 0;
		C[0].slots[50] = 1;
        C[0].slots[51] = 2;
        C[0].slots[52] = -1;
        C[0].slots[53] = 1;
        C[0].slots[54] = -1;
        C[0].slots[55] = 1;
        C[0].slots[56] = -1;
        C[0].slots[57] = -1;
        C[0].slots[58] = 0;
        C[0].slots[59] = 0;
		
		C[1].period = 15;
        C[1].slots[0] = -1;
        C[1].slots[1] = -1;
        C[1].slots[2] = 3;
        C[1].slots[3] = 4;
        C[1].slots[4] = -1;
        C[1].slots[5] = -1;
        C[1].slots[6] = 3;
        C[1].slots[7] = 4;
        C[1].slots[8] = -1;
        C[1].slots[9] = -1;
        C[1].slots[10] = -1;
        C[1].slots[11] = -1;
		C[1].slots[12] = 3;
        C[1].slots[13] = 0;
        C[1].slots[14] = -1;
        C[1].slots[15] = 3;
        C[1].slots[16] = 4;
        C[1].slots[17] = -1;
        C[1].slots[18] = -1;
        C[1].slots[19] = -1;
        C[1].slots[20] = -1;
        C[1].slots[21] = -1;
        C[1].slots[22] = -1;
        C[1].slots[23] = 3;
		C[1].slots[24] = -1;
        C[1].slots[25] = -1;
        C[1].slots[26] = -1;
        C[1].slots[27] = 4;
        C[1].slots[28] = 3;
        C[1].slots[29] = 0;
        C[1].slots[30] = 3;
        C[1].slots[31] = 4;
		C[1].slots[32] = -1;
		C[1].slots[33] = -1;
        C[1].slots[34] = -1;
        C[1].slots[35] = 3;
        C[1].slots[36] = -1;
        C[1].slots[37] = -1;
        C[1].slots[38] = -1;
        C[1].slots[39] = 4;
        C[1].slots[40] = -1;
        C[1].slots[41] = -1;
        C[1].slots[42] = 3;
        C[1].slots[43] = -1;
        C[1].slots[44] = 0;
		C[1].slots[45] = 3;
        C[1].slots[46] = -1;
        C[1].slots[47] = -1;
        C[1].slots[48] = 4;
        C[1].slots[49] = -1;
        C[1].slots[50] = -1;
        C[1].slots[51] = -1;
        C[1].slots[52] = 3;
        C[1].slots[53] = -1;
        C[1].slots[54] = 4;
        C[1].slots[55] = -1;
        C[1].slots[56] = 3;
		C[1].slots[57] = 0;
        C[1].slots[58] = -1;
        C[1].slots[59] = -1;
    }
	
	task void PermutateCipher()
	{
		int chunks1[20],chunks2[20],i,j,k,l,lb,lb1,ub,ub1,temp1,extra,temp3,temp2,n_exec,divisor,counter;
		bool flag;
		for (i = 0;i < 20;i++)
		{
			chunks1[i] = 0;
			chunks2[i] = 0;
		}
		for (i = 0;i < NUM_OF_CLUSTERS;i++)
		{
			n_exec = (HYPERPERIOD-1)/C[i].period;
			for (j = 0;j < n_exec;j++)
			{
				lb = j * C[i].period;
				ub = (j+1) * C[i].period - 1;
				counter = 0;
				for (k = lb;k <= ub;k++)
				{
					if (C[i].slots[k] >= 0)
					{
						chunks1[counter] = C[i].slots[k];
						counter ++;
					}
				}
				key_select = (key_select+1)%C[i].num_of_keys;
				if (counter == C[i].key_length[key_select])
				{
					for (k = 0;k < C[i].key_length[key_select];k++)
					{
						chunks2[k] = chunks1[C[i].key[key_select][k] - 1];
					}
					temp2 = 0;
					temp3 = lb;
					while (temp2 < counter)
					{
						if (C[i].slots[temp3] >= 0)
						{
							C[i].slots[temp3] = chunks2[temp2];
							temp2 = temp2 + 1;
						}
						temp3 = temp3 + 1;
					}
				}
				else if (counter < C[i].key_length[key_select])
				{
					extra = C[i].key_length[key_select] - counter; 
					temp1 = counter;
					while (temp1 < counter+extra)
					{
						chunks1[temp1] = -1;
						temp1 = temp1 + 1;
					}
					for (k = 0;k < C[i].key_length[key_select];k++)
					{
						chunks2[k] = chunks1[C[i].key[key_select][k] - 1];
					}
					temp2 = 0;
					temp3 = lb;
					temp1 = 0;
					while (temp1 < counter)
					{
						if (C[i].slots[temp3] >= 0)
						{
							if (chunks2[temp2] >= 0)
							{
								C[i].slots[temp3] = chunks2[temp2];
								temp1 = temp1 + 1;
								temp2 = temp2 + 1;
							}
							else
							{
								while (chunks2[temp2] == -1)
								{
									temp2 = temp2 + 1;
								}
								C[i].slots[temp3] = chunks2[temp2];
								temp2 = temp2 + 1;
								temp1 = temp1 + 1;
							}
						}
						temp3 = temp3 + 1;
					}	
				}
				else
				{
					divisor = counter/C[i].key_length[key_select];
					flag = FALSE;
					if (counter%C[i].key_length[key_select] > 0)
					{
						divisor = divisor + 1;
						flag = TRUE;
						extra = C[i].key_length[key_select] - counter%C[i].key_length[key_select]; 
						temp1 = counter;
						while (temp1 < counter+extra)
						{
							chunks1[temp1] = -1;
							temp1 = temp1 + 1;
						}
					}
					for (k = 0;k < divisor;k++)
					{	
						lb1 = k * C[i].key_length[key_select];
						ub1 = (k + 1)*C[i].key_length[key_select] - 1;
						for (l = 0;l < C[i].key_length[key_select];l++)
						{
							chunks2[k*C[i].key_length[key_select] + l] = chunks1[k*C[i].key_length[key_select] + C[i].key[key_select][l] - 1];
						}
					}
					temp2 = 0;
					temp3 = lb;
					temp1 = 0;
					while (temp1 < counter)
					{
						if (C[i].slots[temp3] >= 0)
						{
							if (chunks2[temp2] >= 0)
							{
								C[i].slots[temp3] = chunks2[temp2];
								temp1 = temp1 + 1;
								temp2 = temp2 + 1;
							}
							else
							{
								while (chunks2[temp2] == -1)
								{
									temp2 = temp2 + 1;
								}
								C[i].slots[temp3] = chunks2[temp2];
								temp2 = temp2 + 1;
								temp1 = temp1 + 1;
							}
						}
						temp3 = temp3 + 1;
					}	
				}
			}
		}
		post updateSchedule();
	}
	
    task void initializeSchedule()
    {
        atomic
        {
            int i, j, k;
            nx_uint16_t temp, count;
            for (i = 0;i < HYPERPERIOD-1;i++)
            {
                BaseSchedule[i].s = -1;
                BaseSchedule[i].r = -1;
                BaseSchedule[i].fid = -1;
                //BaseSchedule[i].rate = -1;
            }

            for (i = 0;i < NUM_OF_CLUSTERS;i++)
            {
                for (j = 0;j < NUM_OF_FLOWS;j++)
                {
                    temp = 0;
                    count = 0;
                    for (k = 0;k < HYPERPERIOD - 1;k++)
                    {
                        if (C[i].slots[k] == j+1 && count < F[j].n_inst)
                        {
                            BaseSchedule[k].fid = j+1;
                            BaseSchedule[k].s = F[j].route[temp][0];
                            BaseSchedule[k].r = F[j].route[temp][1];
                            //BaseSchedule[k].rate = F[j].period;
                            temp = temp + 1;
                            count = count + 1;
                            
                            //if (count%F[j].period == 0)
							if (temp == F[j].n_hops)
                            {
                                temp = 0;
                            }
                        }
                    }
                }
            }      
        }
    }
	
	task void updateSchedule()
	{
		//call Leds.led0On();
		atomic
        {
            int i, j, k;
            nx_uint16_t temp, count;
			
			for (i = 0;i < HYPERPERIOD-1;i++)
			{
				BaseSchedule[i].fid = -1;
				BaseSchedule[i].s = -1;
				BaseSchedule[i].r = -1;
			}

            for (i = 0;i < NUM_OF_CLUSTERS;i++)
            {
                for (j = 0;j < NUM_OF_FLOWS;j++)
                {
                    temp = 0;
                    count = 0;
                    for (k = 0;k < HYPERPERIOD - 1;k++)
                    {
                        if (C[i].slots[k] == j+1 && count < F[j].n_inst)
                        {
                            BaseSchedule[k].fid = j+1;
                            BaseSchedule[k].s = F[j].route[temp][0];
                            BaseSchedule[k].r = F[j].route[temp][1];
                            temp = temp + 1;
                            
							//if (count%F[j].period == 0)
                            if (temp == F[j].n_hops)
                            {
                                temp = 0;
								count = count + 1;
                            }
                        }
                    }
                }
            }      
        }
		//call Leds.led0Off();
	}

    event void Timer1.fired()
    {
		if (lowpowersignal == FALSE)
		{
			if (BaseSchedule[timeslot].s == TOS_NODE_ID)
			{
				rcm = (radio_count_msg_t*)call Packet.getPayload(&packet_s, sizeof(radio_count_msg_t));
				if (rcm == NULL) 
				{
					return;
				}
				else
				{
					rcm->Mantissa = Buffer1[(BaseSchedule[timeslot].fid)];
					rcm->Exponent = Buffer2[(BaseSchedule[timeslot].fid)];
					rcm->fid = BaseSchedule[timeslot].fid;
					if (call AMSend.send(BaseSchedule[timeslot].r, &packet_s, sizeof(radio_count_msg_t)) == SUCCESS) 
					{	
					}
				}
			}
			else if (BaseSchedule[timeslot].r == TOS_NODE_ID)
			{
				rcv = (radio_count_msg_t*)call Packet.getPayload(&packet_r, sizeof(radio_count_msg_t));
				recvBuf = signal R_A.receive(&packet_r, rcv, sizeof(radio_count_msg_t));
			}
			call Leds.led0Toggle();
		}
		else
		{
			//rcv_b = (radio_count_msg_t*)call Packet.getPayload(&packet_rb, sizeof(radio_count_msg_t));
            //sendBuf = signal R_B.receive(&packet_rb, rcv_b, sizeof(radio_count_msg_t));
			lowpowersignal = FALSE;
			//post PermutateCipher();
		}
		
        timeslot = timeslot + 1;
        
		if (timeslot == HYPERPERIOD - 1)
		{
			lowpowersignal = TRUE;
		}
		
		if (timeslot == HYPERPERIOD)
        {
            timeslot = 0;	
        }
    }

    event void AMSend.sendDone(message_t* bufPtr, error_t error) 
    {
        
        if (&packet_s == bufPtr) 
        {
        }
    }
  
    event message_t* R_A.receive(message_t* bufPtr, void* payload, uint8_t len) 
    {
        radio_count_msg_t * r1 = (radio_count_msg_t*)payload;
        val1 = r1->Mantissa;
        val2 = r1->Exponent;
        index = r1->fid;
        Buffer1[index] = val1;
        Buffer2[index] = val2;

        if (len != sizeof(radio_count_msg_t)) 
        {
            return bufPtr;
        }
        else 
        {
            return bufPtr;            
        }
    }  
	
	event message_t* R_B.receive(message_t* bufPtr, void* payload, uint8_t len) 
    {
		int16_t j,k,l,val;
		
        rateMsg_t* r2 = (rateMsg_t*)payload;

		if (r2 != NULL)
		{
		
			if (len != sizeof(rateMsg_t)) 
			{
				return bufPtr;
			}
			else 
			{
				val = r2 -> R;
				
				for (j = 0;j < NUM_OF_CONTROLS;j++)
				{
					k = val%10;
					Cntl[j].period = Cntl[j].available_periods[k];
					for (l = 0;l < NUM_OF_FLOWS;l++)
					{
						if (F[l].cntl_ID == j+1)
						{
							F[l].period = Cntl[j].period;
							F[l].n_inst = (HYPERPERIOD-1)/Cntl[j].period;
						}
					}	
					val = val/10;
				}				
				post updateSchedule();
				return bufPtr;            
			}
		}
		//post PermutationCipher();
		return bufPtr;
    }  
}	