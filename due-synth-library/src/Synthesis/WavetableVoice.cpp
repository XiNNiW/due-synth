#include <Synthesis/SineWavetableOscillator.h>
#include <Synthesis/ADSREnvelopeGenerator.h>
#include <math.h>
#include <Synthesis/WavetableVoice.h>

WavetableVoice::WavetableVoice():IWavetableVoice() {
	this->oscillator = new SineWavetableOscillator();
	this->envelope = new ADSREnvelopeGenerator(0,0,0,0);
}

WavetableVoice::~WavetableVoice() {
	delete this->oscillator;
	delete this->envelope;
}

long WavetableVoice::nextSample(){
	return this->oscillator->nextSample()*this->envelope->advance();
}

void WavetableVoice::playNote(int noteNumber, int velocity){
	if(velocity>0){
		this->envelope->start();
	}else{
		this->envelope->stop();
	}

	float referenceFrequency = 220.0f;
	int referenceNote = 57;
	float numberOfNotesInAnOctave = 12.0f;
	float frequency = referenceFrequency*exp2f((float)(noteNumber-referenceNote)/numberOfNotesInAnOctave);
	this->oscillator->setFrequency(frequency);
}

