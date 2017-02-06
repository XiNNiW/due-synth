#include <SineWavetableOscillator.h>
#include <WavetableSynth.h>

WavetableSynth::WavetableSynth() {
	this->oscillator = new SineWavetableOscillator();
}

long WavetableSynth::nextSample(){
	return this->oscillator->nextSample();

}

WavetableSynth::~WavetableSynth() {
	// TODO Auto-generated destructor stub
}

