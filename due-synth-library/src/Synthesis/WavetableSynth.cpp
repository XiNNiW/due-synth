#include <Synthesis/WavetableSynth.h>

#include <Synthesis/SineWavetableOscillator.h>
#include <math.h>

WavetableSynth::WavetableSynth():IWavetableSynth() {
	this->oscillator = new SineWavetableOscillator();
}

long WavetableSynth::nextSample(){
	return this->oscillator->nextSample();

}

void WavetableSynth::playNote(int noteNumber, int velocity){
	float referenceFrequency = 220.0f;
	int referenceNote = 57;
	float numberOfNotesInAnOctave = 12.0f;
	float frequency = referenceFrequency*exp2f((float)(noteNumber-referenceNote)/numberOfNotesInAnOctave);
	this->oscillator->setFrequency(frequency);
}

WavetableSynth::~WavetableSynth() {
	// TODO Auto-generated destructor stub
}

