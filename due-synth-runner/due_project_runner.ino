#include "Arduino.h"

#include <Synthesis/IWavetableVoice.h>
#include <Synthesis/WavetableVoice.h>
#include <DigitalAudioConverter.h>
#include <Synthesis/ADSREnvelopeGenerator.h>


WavetableVoice* synthVoice = new WavetableVoice();
ADSREnvelopeGenerator* envelope2 = new ADSREnvelopeGenerator(10,10,1,10);
IDigitalAudioConverter* dac = DigitalAudioConverter::instance();
long counter = 0;
bool status= false;


void setup(){
	Serial.begin(9600);
	Serial.println("hi");
	initializeAnalogInputs();
	initializeAudioOutputs();
	initializeSynthVoice();
	startDigitalAudio();

}

void TC4_Handler() //Interrupt at 44.1KHz rate (every 22.6us)
{
	TC_GetStatus(TC1, 1); //Clear status to fire again the interrupt.
	long nextSample = synthVoice->nextSample()/16;
	analogWrite(DAC1, nextSample+2048);
}

void loop()
{
	long frequency = analogRead(A1);
	synthVoice->playNote(60,100);
	counter++;
	long delay = 10;
	if (counter >= delay) {
		if(status){
			Serial.println("stop");
			synthVoice->playNote(60,0);
			envelope2->stop();
			status=false;

		}else{
			Serial.println("play");
			synthVoice->playNote(60,100);
			envelope2->start();
//			status=true;
		}
		Serial.println("reset");
		counter=0;
	}
}

void initializeSynthVoice(){
	dac->addAudioGeneratorToOutput(synthVoice);
}

void startDigitalAudio(){
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
};

void initializeAudioOutputs(){
	pinMode(DAC1, OUTPUT);
	analogWriteResolution(12);
};

void initializeAnalogInputs(){
	pinMode(A1, INPUT);
	analogReadResolution(12);
};

