#include "Permute.h"

configuration LowPowerAppC {}
implementation 
{
    components MainC, LowPowerC as App1, LedsC;
    components new AMSenderC(AM_RADIO_COUNT_MSG+5);
    
    components new TimerMilliC() as Timer1;
    components new TimerMilliC() as Timer2;
    components ActiveMessageC;
	  
    App1.Boot -> MainC.Boot;
  
    App1.AMSend -> AMSenderC;
    App1.AMControl -> ActiveMessageC;
    App1.Leds -> LedsC;
    App1.Timer1 -> Timer1;
    App1.Timer2 -> Timer2;
    App1.Packet -> AMSenderC;

    components new Msp430Adc12ClientAutoRVGC() as AutoAdc;
	App1.Resource -> AutoAdc;
	AutoAdc.AdcConfigure -> App1;
	App1.MultiChannel -> AutoAdc.Msp430Adc12MultiChannel;
}