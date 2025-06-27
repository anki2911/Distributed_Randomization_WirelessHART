#include "Permute.h"

configuration SendingBuffer_AppC {}
implementation 
{
    components MainC, SendingBufferC as App1, LedsC;
    components new AMSenderC(AM_RADIO_COUNT_MSG);
    components new AMReceiverC(AM_RADIO_COUNT_MSG) as R_A;
	components new AMReceiverC(AM_RADIO_COUNT_MSG+5) as R_B;
  
    components new TimerMilliC() as Timer1;
    components new TimerMilliC() as Timer2;
    //components new TimerMilliC() as Timer3;
    //components new TimerMilliC() as Timer4;
    components ActiveMessageC;
  
    App1.Boot -> MainC.Boot;
  
    App1.AMSend -> AMSenderC;
    App1.AMControl -> ActiveMessageC;
    App1.Leds -> LedsC;
    App1.Timer1 -> Timer1;
    App1.Timer2 -> Timer2;
    //App1.Timer3 -> Timer3;
    //App1.Timer4 -> Timer4;
    App1.Packet -> AMSenderC;
    App1.R_A -> R_A;
	App1.R_B -> R_B;
    App1.Packet -> R_A;
	App1.Packet -> R_B;


    components new Msp430Adc12ClientAutoRVGC() as AutoAdc;
	App1.Resource -> AutoAdc;
	AutoAdc.AdcConfigure -> App1;
	App1.MultiChannel -> AutoAdc.Msp430Adc12MultiChannel;
}