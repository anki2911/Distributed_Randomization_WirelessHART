#include "Timer.h"
#include "Permute.h"

module SendingBufferC @safe() 
{
  
    uses interface Leds;
    uses interface Boot;
  
    uses interface AMSend;
    uses interface Receive as R_A;
	uses interface Receive as R_B;
    uses interface Timer<TMilli> as Timer1;
    uses interface Timer<TMilli> as Timer2;
    //uses interface Timer<TMilli> as Timer3;
    //uses interface Timer<TMilli> as Timer4;
    uses interface SplitControl as AMControl;
    uses interface Packet;

    uses  interface Resource;
   	uses 	interface Msp430Adc12MultiChannel as MultiChannel;
    uses interface PacketAcknowledgements;
	provides 	interface AdcConfigure<const msp430adc12_channel_config_t*>;
    
}
implementation 
{
    static int32_t val1;
	static int32_t val2;
	static int8_t buf_count;

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
    
    //	ADCValues
	nx_uint16_t adcValues[2];
    uint16_t buffer[3];
    message_t packet;

    static slot_info_t BaseSchedule[65]; 

    task void initializeFlow();
    task void assignFlowstoSlots();
    task void initializeSchedule();
	task void PermutateCipher();
	task void updateSchedule();
	task void initializeCluster();

    const msp430adc12_channel_config_t config = {
		INPUT_CHANNEL_A5, REFERENCE_VREFplus_AVss, REFVOLT_LEVEL_2_5,
		SHT_SOURCE_SMCLK, SHT_CLOCK_DIV_1, SAMPLE_HOLD_64_CYCLES,
		SAMPCON_SOURCE_SMCLK, SAMPCON_CLOCK_DIV_1
	};

    event void Boot.booted() 
    {
		lowpowersignal = FALSE;
		buf_count = 0;
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

            call Resource.request();
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

    event void Resource.granted()
    {
	    atomic 
        {
		    adc12memctl_t memctl[] = { {INPUT_CHANNEL_A0, REFERENCE_VREFplus_AVss}, {INPUT_CHANNEL_A1, REFERENCE_VREFplus_AVss}};

		    if (call MultiChannel.configure(&config, memctl, 2, buffer, 3, 0) != SUCCESS) 
            {

		    }
	    }
	
        // Start a periodic timer to read the ADC
        call Timer1.startPeriodic(50);
        //Hyperperiod = 150ms
        call Timer2.startPeriodic(15);
		//PermutationCipher
		//call Timer3.startPeriodic(15*(HYPERPERIOD-1));
    }

    task void initializeFlow()
    {
        //FLOW 1
        F[0].flow_id = 1;
		F[0].cntl_ID = 1;
		F[0].cluster_id = 1;
        F[0].n_hops = 1;
        F[0].period = 16;
		F[0].n_inst = (HYPERPERIOD-1)/F[0].period;
        F[0].route[0][0] = 3;
        F[0].route[0][1] = 4;
		
		
		
        /*F[0].route[1][0] = 5;
        F[0].route[1][1] = 7;
        F[0].route[2][0] = 7;
        F[0].route[2][1] = 9;*/

        //FLOW 2
        /*F[1].flow_id = 2;
		F[1].cntl_ID = 2;
		F[1].cluster_id = 1;
        F[1].n_hops = 1;
        F[1].period = 16;
		F[1].n_inst = (HYPERPERIOD-1)/F[1].period;
        F[1].route[0][0] = 6;
        F[1].route[0][1] = 8;*/
        
		/*F[1].route[1][0] = 5;
        F[1].route[1][1] = 8;
        F[1].route[2][0] = 8;
        F[1].route[2][1] = 9;*/

        //FLOW 3
        /*F[2].flow_id = 3;
		F[2].cntl_ID = 3;
		F[2].cluster_id = 2;
        F[2].n_hops = 1;
        F[2].period = 32;
		F[2].n_inst = (HYPERPERIOD-1)/F[2].period;
        F[2].route[0][0] = 6;
        F[2].route[0][1] = 9;*/
        
		/*F[2].route[1][0] = 6;
        F[2].route[1][1] = 7;
        F[2].route[2][0] = 7;
        F[2].route[2][1] = 9;*/

        //FLOW 4
        /*F[3].flow_id = 4;
		F[3].cntl_ID = 4;
        F[3].cluster_id = 2;
        F[3].n_hops = 1;
        F[3].period = 32;
		F[3].n_inst = (HYPERPERIOD-1)/F[3].period;
        F[3].route[0][0] = 6;
        F[3].route[0][1] = 10;*/
		
        /*F[3].route[1][0] = 6;
        F[3].route[1][1] = 8;
        F[3].route[2][0] = 8;
        F[3].route[2][1] = 9;*/       
    }
	
	task void initializeCluster()
    {
        int i;
    
        C[0].cl_id = 1;
        C[0].period = 16;
        C[0].key[0] = 4;
        C[0].key[1] = 1;
        C[0].key[2] = 2;
        C[0].key[3] = 3;
		C[0].key_length = 4;
        C[0].util = 0;
		
		/*C[1].cl_id = 2;
        C[1].period = 32;
        C[1].key[0] = 3;
        C[1].key[1] = 1;
        C[1].key[2] = 4;
        C[1].key[3] = 2;
        C[1].util = 0;*/
    
        /*C[1].cl_id = 2;
        C[1].period = 32;
        C[1].key[0] = 2;
        C[1].key[1] = 4;
        C[1].key[2] = 1;
        C[1].key[3] = 3;
        C[1].util = 0;
    
        C[2].cl_id = 3;
        C[2].period = 64;
        C[2].key[0] = 3;
        C[2].key[1] = 4;
        C[2].key[2] = 2;
        C[2].key[3] = 1;
        C[2].util = 0;*/
    
        for (i = 0;i < HYPERPERIOD-1;i++)
        {
            C[0].slots[i] = -1;
            //C[1].slots[i] = -1;
           // C[2].slots[i] = -1;
            BaseSchedule[i].s = -1;
            BaseSchedule[i].r = -1;
            BaseSchedule[i].fid = -1;
        }
    }
	
    task void assignFlowstoSlots()
    {
		Cntl[0].period = 16;
		//Cntl[1].period = 16;
		//Cntl[2].period = 32;
		//Cntl[3].period = 32;
		
		Cntl[0].available_periods[0] = 16;
		Cntl[0].available_periods[1] = 32;
		Cntl[0].available_periods[2] = 64;
		/*Cntl[1].available_periods[0] = 16;
		Cntl[1].available_periods[1] = 32;
		Cntl[1].available_periods[2] = 64;
		Cntl[2].available_periods[0] = 32;
		Cntl[2].available_periods[1] = 64;
		Cntl[3].available_periods[0] = 32;
		Cntl[3].available_periods[1] = 64;*/
		
		
        C[0].util = 10;
		C[0].period = 16;
		C[0].slots[0] = 1;
		C[0].slots[1] = 0;
		C[0].slots[2] = 0;
        C[0].slots[3] = 0;
        C[0].slots[4] = 0;
        C[0].slots[5] = 0;
        C[0].slots[6] = 0;
        C[0].slots[7] = 0;
        C[0].slots[8] = 0;
        C[0].slots[9] = 0;
        C[0].slots[10] = 0;
        C[0].slots[11] = 0;
		C[0].slots[12] = 0;
        C[0].slots[13] = 0;
        C[0].slots[14] = 0;
        C[0].slots[15] = 0;
		C[0].slots[16] = 1;
		C[0].slots[17] = 0;
		C[0].slots[18] = 0;
        C[0].slots[19] = 0;
        C[0].slots[20] = 0;
        C[0].slots[21] = 0;
        C[0].slots[22] = 0;
        C[0].slots[23] = 0;
        C[0].slots[24] = 0;
        C[0].slots[25] = 0;
        C[0].slots[26] = 0;
        C[0].slots[27] = 0;
		C[0].slots[28] = 0;
        C[0].slots[29] = 0;
        C[0].slots[30] = 0;
        C[0].slots[31] = 0;
		C[0].slots[32] = 1;
		C[0].slots[33] = 0;
		C[0].slots[34] = 0;
        C[0].slots[35] = 0;
        C[0].slots[36] = 0;
        C[0].slots[37] = 0;
        C[0].slots[38] = 0;
        C[0].slots[39] = 0;
        C[0].slots[40] = 0;
        C[0].slots[41] = 0;
        C[0].slots[42] = 0;
        C[0].slots[43] = 0;
		C[0].slots[44] = 0;
        C[0].slots[45] = 0;
        C[0].slots[46] = 0;
        C[0].slots[47] = 0;
		C[0].slots[48] = 1;
		C[0].slots[49] = 0;
		C[0].slots[50] = 0;
        C[0].slots[51] = 0;
        C[0].slots[52] = 0;
        C[0].slots[53] = 0;
        C[0].slots[54] = 0;
        C[0].slots[55] = 0;
        C[0].slots[56] = 0;
        C[0].slots[57] = 0;
        C[0].slots[58] = 0;
        C[0].slots[59] = 0;
		C[0].slots[60] = 0;
        C[0].slots[61] = 0;
        C[0].slots[62] = 0;
        C[0].slots[63] = 0;
		
	/*	C[1].util = 12;
		C[1].period = 32;
        C[1].slots[0] = -1;
        C[1].slots[1] = -1;
        C[1].slots[2] = -1;
        C[1].slots[3] = 3;
        C[1].slots[4] = -1;
        C[1].slots[5] = 0;
        C[1].slots[6] = -1;
        C[1].slots[7] = -1;
        C[1].slots[8] = 0;
        C[1].slots[9] = 0;
        C[1].slots[10] = -1;
        C[1].slots[11] = -1;
		C[1].slots[12] = 0;
        C[1].slots[13] = -1;
        C[1].slots[14] = -1;
        C[1].slots[15] = 0;
        C[1].slots[16] = -1;
        C[1].slots[17] = -1;
        C[1].slots[18] = -1;
        C[1].slots[19] = 4;
        C[1].slots[20] = -1;
        C[1].slots[21] = 0;
        C[1].slots[22] = -1;
        C[1].slots[23] = -1;
		C[1].slots[24] = 0;
        C[1].slots[25] = 0;
        C[1].slots[26] = -1;
        C[1].slots[27] = -1;
        C[1].slots[28] = 0;
        C[1].slots[29] = -1;
        C[1].slots[30] = -1;
        C[1].slots[31] = 0;
		C[1].slots[33] = -1;
        C[1].slots[34] = -1;
        C[1].slots[35] = -1;
        C[1].slots[36] = 3;
        C[1].slots[37] = -1;
        C[1].slots[38] = 0;
        C[1].slots[39] = -1;
        C[1].slots[40] = -1;
        C[1].slots[41] = 0;
        C[1].slots[42] = 0;
        C[1].slots[43] = -1;
        C[1].slots[44] = -1;
		C[1].slots[45] = 0;
        C[1].slots[46] = -1;
        C[1].slots[47] = -1;
        C[1].slots[48] = 0;
        C[1].slots[49] = -1;
        C[1].slots[50] = -1;
        C[1].slots[51] = -1;
        C[1].slots[52] = 4;
        C[1].slots[53] = -1;
        C[1].slots[54] = 0;
        C[1].slots[55] = -1;
        C[1].slots[56] = -1;
		C[1].slots[57] = 0;
        C[1].slots[58] = 0;
        C[1].slots[59] = -1;
        C[1].slots[60] = -1;
        C[1].slots[61] = 0;
        C[1].slots[62] = -1;
        C[1].slots[63] = -1;*/
    }
	
	task void PermutateCipher()
	{
		uint16_t chunks1[20],chunks2[20],i,j,k,l,lb,lb1,ub,ub1,temp1,extra,temp3,temp2,n_exec,divisor,counter;
		bool flag;
		call Leds.led1On();
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
				if (counter == C[i].key_length)
				{
					for (k = 0;k < C[i].key_length;k++)
					{
						chunks2[k] = chunks1[C[i].key[k] - 1];
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
				else if (counter < C[i].key_length)
				{
					extra = C[i].key_length - counter; 
					temp1 = counter;
					while (temp1 < counter+extra)
					{
						chunks1[temp1] = -1;
						temp1 = temp1 + 1;
					}
					for (k = 0;k < C[i].key_length;k++)
					{
						chunks2[k] = chunks1[C[i].key[k] - 1];
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
					divisor = counter/C[i].key_length;
					flag = FALSE;
					if (counter%C[i].key_length > 0)
					{
						divisor = divisor + 1;
						flag = TRUE;
						extra = C[i].key_length - counter%C[i].key_length; 
						temp1 = counter;
						while (temp1 < counter+extra)
						{
							chunks1[temp1] = -1;
							temp1 = temp1 + 1;
						}
					}
					for (k = 0;k < divisor;k++)
					{	
						lb1 = k * C[i].key_length;
						ub1 = (k + 1)*C[i].key_length - 1;
						for (l = 0;l < C[i].key_length;l++)
						{
							chunks2[k*C[i].key_length + l] = chunks1[k*C[i].key_length + C[i].key[l] - 1];
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
			for (k = 0;k < HYPERPERIOD - 1;k++)
            {
				BaseSchedule[k].fid = -1;
                BaseSchedule[k].s = -1;
                BaseSchedule[k].r = -1;
			}
			for (j = 0;j < NUM_OF_FLOWS;j++)
            {
				temp1 = 0;
                for (k = 0;k < HYPERPERIOD - 1;k++)
                {
					if (C[i].slots[k] == j+1)
                    {
                        BaseSchedule[k].fid = j+1;
                        BaseSchedule[k].s = F[j].route[temp1][0];
                        BaseSchedule[k].r = F[j].route[temp1][1];
                        temp1 = temp1 + 1;
						if (temp1 == F[j].n_hops)
                        {
                            temp1 = 0;	
                        }
					}
				}
			}
		}
		//post updateSchedule();
		call Leds.led1Off();
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
		call Leds.led0On();
		atomic
        {
            int i, j, k;
            nx_uint16_t temp, count;

            for (i = 0;i < NUM_OF_CLUSTERS;i++)
            {
                for (j = 0;j < NUM_OF_FLOWS;j++)
                {
                    temp = 0;
                    count = 0;
                    for (k = 0;k < HYPERPERIOD - 1;k++)
                    {
                        if (C[i].slots[k] == j+1)
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
						else
						{
							BaseSchedule[k].fid = -1;
                            BaseSchedule[k].s = -1;
                            BaseSchedule[k].r = -1;
						
						}
                    }
                }
            }      
        }
		call Leds.led0Off();
	}
	
    task void getData()
	{
		// Read ADC values
		call MultiChannel.getData();
	}

    event void Timer1.fired() 
    {
        post getData();
    }

    event void Timer2.fired()
    {
		uint16_t chunks1[20],chunks2[20],i,j,k,l,lb,lb1,ub,ub1,temp1,extra,temp3,temp2,n_exec,divisor,counter;
		bool flag;
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
					atomic
					{
						rcm->Mantissa = Buffer1[(BaseSchedule[timeslot].fid)];
						rcm->Exponent = Buffer2[(BaseSchedule[timeslot].fid)];
					}
					rcm->fid = BaseSchedule[timeslot].fid;
					if (call AMSend.send(BaseSchedule[timeslot].r, &packet_s, sizeof(radio_count_msg_t)) == SUCCESS) 
					{
						dbg("RadioCountToLedsC", "RadioCountToLedsC: packet sent.\n", counter);	
					}
					//for Cipher
					BaseSchedule[timeslot].fid = -1;
					BaseSchedule[timeslot].s = -1;
					BaseSchedule[timeslot].r = -1;
				}
				//call Leds.led0Toggle();
			} 
			else if (BaseSchedule[timeslot].r == TOS_NODE_ID)
			{
				rcv = (radio_count_msg_t*)call Packet.getPayload(&packet_r, sizeof(radio_count_msg_t));
				recvBuf = signal R_A.receive(&packet_r, rcv, sizeof(radio_count_msg_t));
				//for Cipher
				BaseSchedule[timeslot].fid = -1;
				BaseSchedule[timeslot].s = -1;
				BaseSchedule[timeslot].r = -1;
			}
		}
		else
		{
			rcv_b = (radio_count_msg_t*)call Packet.getPayload(&packet_rb, sizeof(radio_count_msg_t));
            sendBuf = signal R_B.receive(&packet_rb, rcv_b, sizeof(radio_count_msg_t));
			lowpowersignal = FALSE;
			//post PermutationCipher();
		}
		
        timeslot = timeslot + 1;
        
		if (timeslot == HYPERPERIOD - 1)
		{
			//call Leds.led1On();
			for (i = 0;i < 20;i++)
			{
				chunks1[i] = 0;
				chunks2[i] = 0;
			}
		for (i = 0;i < NUM_OF_CLUSTERS;i++)
		{
			n_exec = (HYPERPERIOD- 1)/C[i].period;
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
				if (counter == C[i].key_length)
				{
					for (k = 0;k < C[i].key_length;k++)
					{
						chunks2[k] = chunks1[C[i].key[k] - 1];
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
				else if (counter < C[i].key_length)
				{
					extra = C[i].key_length - counter; 
					temp1 = counter;
					while (temp1 < counter+extra)
					{
						chunks1[temp1] = -1;
						temp1 = temp1 + 1;
					}
					for (k = 0;k < C[i].key_length;k++)
					{
						chunks2[k] = chunks1[C[i].key[k] - 1];
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
					divisor = counter/C[i].key_length;
					flag = FALSE;
					if (counter%C[i].key_length > 0)
					{
						divisor = divisor + 1;
						flag = TRUE;
						extra = C[i].key_length - counter%C[i].key_length; 
						temp1 = counter;
						while (temp1 < counter+extra)
						{
							chunks1[temp1] = -1;
							temp1 = temp1 + 1;
						}
					}
					for (k = 0;k < divisor;k++)
					{	
						lb1 = k * C[i].key_length;
						ub1 = (k + 1)*C[i].key_length - 1;
						for (l = 0;l < C[i].key_length;l++)
						{
							chunks2[k*C[i].key_length + l] = chunks1[k*C[i].key_length + C[i].key[l] - 1];
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
			for (j = 0;j < NUM_OF_FLOWS;j++)
            {
				temp1 = 0;
                for (k = 0;k < HYPERPERIOD - 1;k++)
                {
					if (C[i].slots[k] == j+1)
                    {
                        BaseSchedule[k].fid = j+1;
                        BaseSchedule[k].s = F[j].route[temp1][0];
                        BaseSchedule[k].r = F[j].route[temp1][1];
                        temp1 = temp1 + 1;
						if (temp1 == F[j].n_hops)
                        {
                            temp1 = 0;	
                        }
					}
				}
			}
			
		}
		//call Leds.led1Off();
            timeslot = 0;	
		}
		
    }

    event void AMSend.sendDone(message_t* bufPtr, error_t error) 
    {    
        if (&packet_s == bufPtr) 
        {
			call Leds.led1Toggle();
        }
    }
  
    event message_t* R_A.receive(message_t* bufPtr, void* payload, uint8_t len) 
    {
        radio_count_msg_t * r1 = (radio_count_msg_t*)payload;
        val1 = r1->Mantissa;
        val2 = r1->Exponent;
        index = r1->fid;
        atomic
		{
			Buffer1[index] = val1;
			Buffer2[index] = val2;
		}
		
        if (len != sizeof(radio_count_msg_t)) 
        {
            return bufPtr;
        }
        else 
        {
            return bufPtr;            
        }
    }  

    async event void MultiChannel.dataReady(uint16_t *buf, uint16_t numSamples)
	{
		// Copy sensor readings
		adcValues[0] = buf[1];
		adcValues[1] = buf[2];
		
		Buffer1[1] = adcValues[0];
        Buffer2[1] = adcValues[1];
        
        /*if (adcValues[1] >= 3000) 
        {
            Buffer1[4] = adcValues[0];
            Buffer2[4] = adcValues[1];
        }
        else if (adcValues[1] >= 2000 && adcValues[1] < 3000) 
        {
            Buffer1[3] = adcValues[0];
            Buffer2[3] = adcValues[1];
        }
        else if (adcValues[1] >= 1000 && adcValues[1] < 2000) 
        {
            Buffer1[2] = adcValues[0];
            Buffer2[2] = adcValues[1];
        }
        else if (adcValues[1] >= 0 && adcValues[1] < 1000) 
        {
            Buffer1[1] = adcValues[0];
            Buffer2[1] = adcValues[1];
        }*/
    }

    async command const msp430adc12_channel_config_t* AdcConfigure.getConfiguration()
	{
		return &config;
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
				//post updateSchedule();
				return bufPtr;            
			}
		}
		//post PermutationCipher();
		return bufPtr;
    }  

}	
