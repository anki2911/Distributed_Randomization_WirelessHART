#include "Timer.h"
#include "Permute.h"

module LowPowerC @safe() 
{
  
    uses interface Leds;
    uses interface Boot;
  
    uses interface AMSend;
    uses interface Timer<TMilli> as Timer1;
    uses interface Timer<TMilli> as Timer2;
    uses interface SplitControl as AMControl;
    uses interface Packet;
	//uses interface CC2420Config;

    uses  interface Resource;
   	uses 	interface Msp430Adc12MultiChannel as MultiChannel;
	provides 	interface AdcConfigure<const msp430adc12_channel_config_t*>;
    
}
implementation 
{

    message_t packet_s;
    static int16_t timeslot;
	static bool flag;
	static int16_t val;
	static int16_t BasePeriods[4];
    
    rateMsg_t* rcm;
    //radio_count_msg_t* rcm;

    //	ADCValues
	nx_uint16_t adcValues[2];
    uint16_t buffer[3];
    int16_t i;

    const msp430adc12_channel_config_t config = {
		INPUT_CHANNEL_A5, REFERENCE_VREFplus_AVss, REFVOLT_LEVEL_2_5,
		SHT_SOURCE_SMCLK, SHT_CLOCK_DIV_1, SAMPLE_HOLD_64_CYCLES,
		SAMPCON_SOURCE_SMCLK, SAMPCON_CLOCK_DIV_1
	};

    event void Boot.booted() 
    {
		timeslot = 0;
		for (i = 0;i < 4;i++)
		{
			atomic{
				BasePeriods[i] = 0;
			}
		}
		atomic{
			flag = FALSE;
		}
        call AMControl.start();
    }

    event void AMControl.startDone(error_t err) 
    {
        if (err == SUCCESS) 
        {  
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
		call Timer1.startPeriodic(200);
		call Timer2.startPeriodic(15);        
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
        timeslot = timeslot + 1;
        if (timeslot == HYPERPERIOD)
        {
			//call CC2420Config.setChannel(16);
			//call CC2420Config.sync();
            timeslot = 0;
			
			atomic{
				
				/*if (flag == TRUE)
				{
					
					rcm = (rateMsg_t*)call Packet.getPayload(&packet_s, sizeof(rateMsg_t));
					
				
					rcm->R = val;
					if (call AMSend.send(AM_BROADCAST_ADDR, &packet_s, sizeof(rateMsg_t)) == SUCCESS) 
					{
						dbg("RadioCountToLedsC", "RadioCountToLedsC: packet sent.\n", counter);	
					}
                
				}*/
                
				
                flag = FALSE;
                call Leds.led1Off();
			}
        }
    }

    event void AMSend.sendDone(message_t* bufPtr, error_t error) 
    {    
        if (&packet_s == bufPtr) 
        {
        }
    }

    async event void MultiChannel.dataReady(uint16_t *buf, uint16_t numSamples)
	{
		int16_t j,k;
		// Copy sensor readings
		adcValues[0] = buf[1];
        
        atomic{
			val = adcValues[0];
			k = val;
			for (j = 0;j < 4;j++)
			{
				if (k%10 != BasePeriods[j])
				{
					BasePeriods[j] = k%10;
					flag = TRUE;
				}
				k = k/10;
		
			}
			if (flag == TRUE)
			{
				call Leds.led1On();
			}   
        }
    }

    async command const msp430adc12_channel_config_t* AdcConfigure.getConfiguration()
	{
		return &config;
	}
}	