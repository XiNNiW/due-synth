#include "Arduino.h"

#include "SineWavetableOscillator.h"

//The setup function is called once at startup of the sketch
SineWavetableOscillator* oscillator = new SineWavetableOscillator();

void setup(){

	//turn on the timer clock in the power management controller
	pmc_set_writeprotect(false);
	pmc_enable_periph_clk(ID_TC4);
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
	analogWrite(DAC1,2048);
}

void TC4_Handler() //Interrupt at 44.1KHz rate (every 22.6us)
{
	TC_GetStatus(TC1, 1); //Clear status to fire again the interrupt.
	long nextSample = oscillator->nextSample()/16;
	analogWrite(DAC1, nextSample+2048);
}

void loop()
{
	long frequency = analogRead(A1);
	oscillator->setFrequency((float)frequency);
}
