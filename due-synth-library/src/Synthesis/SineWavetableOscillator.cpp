#include <Synthesis/SineWavetableOscillator.h>
#include <math.h>

#define WAVETABLE_SIZE 128
namespace sunthesis{
sample sineTable[WAVETABLE_SIZE] = {32767,34375,35979,37575,39160,40729,42279,43806,45307,46777,48213,49613,50972,52287,53554,54772,55937,57046,58097,59086,60012,60873,61665,62388,63040,63619,64124,64552,64905,65180,65377,65495,65535,65495,65377,65180,64905,64552,64124,63619,63040,62388,61665,60873,60012,59086,58097,57046,55937,54772,53554,52287,50972,49613,48213,46777,45307,43806,42279,40729,39160,37575,35979,34375,32767,31159,29555,27959,26374,24805,23255,21728,20227,18757,17321,15921,14562,13247,11980,10762,9597,8488,7437,6448,5522,4661,3869,3146,2494,1915,1410,982,629,354,157,39,0,39,157,354,629,982,1410,1915,2494,3146,3869,4661,5522,6448,7437,8488,9597,10762,11980,13247,14562,15921,17321,18757,20227,21728,23255,24805,26374,27959,29555,31159};



SineWavetableOscillator::SineWavetableOscillator():IWavetableOscillator() {
	this->sampleRate = 44100;
	this->frequency = 0.0;
	this->phase = 0;
}
SineWavetableOscillator::~SineWavetableOscillator(){}

sample SineWavetableOscillator::nextSample() {
	int wavetableIndex = (int)((float)(this->phase*(float)WAVETABLE_SIZE)/((float)this->sampleRate));
	this->phase+=this->frequency;
	this->phase=fmod(this->phase,this->sampleRate);

	return sineTable[wavetableIndex];
}

void SineWavetableOscillator::setFrequency(float frequency) {
	this->frequency = frequency;
}
}






