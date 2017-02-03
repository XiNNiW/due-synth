#include "Arduino.h"
#include "SineWavetableOscillator.h"
//The setup function is called once at startup of the sketch
int counter = 0;
#define maxSamplesNum 128
#define sampleRate 100



volatile int phaseIncrement = 16;



static long sineTable[maxSamplesNum] =
  {
		  0x7ff, 0x86a, 0x8d5, 0x93f, 0x9a9, 0xa11, 0xa78, 0xadd, 0xb40, 0xba1,
		      0xbff, 0xc5a, 0xcb2, 0xd08, 0xd59, 0xda7, 0xdf1, 0xe36, 0xe77, 0xeb4,
		      0xeec, 0xf1f, 0xf4d, 0xf77, 0xf9a, 0xfb9, 0xfd2, 0xfe5, 0xff3, 0xffc,
		      0xfff, 0xffc, 0xff3, 0xfe5, 0xfd2, 0xfb9, 0xf9a, 0xf77, 0xf4d, 0xf1f,
		      0xeec, 0xeb4, 0xe77, 0xe36, 0xdf1, 0xda7, 0xd59, 0xd08, 0xcb2, 0xc5a,
		      0xbff, 0xba1, 0xb40, 0xadd, 0xa78, 0xa11, 0x9a9, 0x93f, 0x8d5, 0x86a,
		      0x7ff, 0x794, 0x729, 0x6bf, 0x655, 0x5ed, 0x586, 0x521, 0x4be, 0x45d,
		      0x3ff, 0x3a4, 0x34c, 0x2f6, 0x2a5, 0x257, 0x20d, 0x1c8, 0x187, 0x14a,
		      0x112, 0xdf, 0xb1, 0x87, 0x64, 0x45, 0x2c, 0x19, 0xb, 0x2,
		      0x0, 0x2, 0xb, 0x19, 0x2c, 0x45, 0x64, 0x87, 0xb1, 0xdf,
		      0x112, 0x14a, 0x187, 0x1c8, 0x20d, 0x257, 0x2a5, 0x2f6, 0x34c, 0x3a4,
		      0x3ff, 0x45d, 0x4be, 0x521, 0x586, 0x5ed, 0x655, 0x6bf, 0x729, 0x794,
			  0x7ff, 0x86a, 0x8d5, 0x93f,0x655, 0x6bf, 0x729, 0x794,
  };

void setup(){


	//turn on the timer clock in the power management controller
	  pmc_set_writeprotect(false);
	  pmc_enable_periph_clk(ID_TC4);
	  SineWavetableOscillator* osc = new SineWavetableOscillator();
	  int fact = osc->nextSample();

	  //we want wavesel 01 with RC
	  TC_Configure(TC1, 1, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK2);
	  TC_SetRC(TC1, 1, 238); // sets <> 44.1 Khz interrupt rate

	  TC_Start(TC1, 1);

	  // enable timer interrupts on the timer
	  TC1->TC_CHANNEL[1].TC_IER=TC_IER_CPCS;
	  TC1->TC_CHANNEL[1].TC_IDR=~TC_IER_CPCS;

	  //Enable the interrupt in the nested vector interrupt controller
	  //TC4_IRQn where 4 is the timer number * timer channels (3) + the channel
	  //number (=(1*3)+1) for timer1 channel1
	  NVIC_EnableIRQ(TC4_IRQn);


	pinMode(DAC1, OUTPUT);
	pinMode(A1, INPUT);
	analogReadResolution(12);
	analogWriteResolution(12);
	analogWrite(DAC1,0);
}

void TC4_Handler() //Interrupt at 44.1KHz rate (every 22.6us)
{
   TC_GetStatus(TC1, 1); //Clear status to fire again the interrupt.


   analogWrite(DAC1, sineTable[counter/32]/4);  // write the selected waveform on DAC0
	counter += phaseIncrement; // modify the indexing to get different frequency

  if (counter >= 32 * (maxSamplesNum-1)){
	  counter = 0;
  }
}


void loop()
{
	phaseIncrement = map(analogRead(A1), 0, 4095, 0, 128);
}
