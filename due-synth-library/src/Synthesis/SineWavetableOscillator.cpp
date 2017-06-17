#include <Synthesis/SineWavetableOscillator.h>
#include <math.h>

#define WAVETABLE_SIZE 128
namespace sunthesis{
static long sineTable[WAVETABLE_SIZE] = { 0, 100, 200, 300, 399, 497, 594, 689, 783, 875,
		965, 1052, 1137, 1219, 1299, 1375, 1448, 1517, 1583, 1644, 1702, 1756,
		1806, 1851, 1892, 1928, 1959, 1986, 2008, 2025, 2038, 2045, 2048, 2045,
		2038, 2025, 2008, 1986, 1959, 1928, 1892, 1851, 1806, 1756, 1702, 1644,
		1583, 1517, 1448, 1375, 1299, 1219, 1137, 1052, 965, 875, 783, 689, 594,
		497, 399, 300, 200, 100, 0, -100, -200, -300, -399, -497, -594, -689,
		-783, -875, -965, -1052, -1137, -1219, -1299, -1375, -1448, -1517,
		-1583, -1644, -1702, -1756, -1806, -1851, -1892, -1928, -1959, -1986,
		-2008, -2025, -2038, -2045, -2048, -2045, -2038, -2025, -2008, -1986,
		-1959, -1928, -1892, -1851, -1806, -1756, -1702, -1644, -1583, -1517,
		-1448, -1375, -1299, -1219, -1137, -1052, -965, -875, -783, -689, -594,
		-497, -399, -300, -200, -100 };


SineWavetableOscillator::SineWavetableOscillator():IWavetableOscillator() {
	this->sampleRate = 44100;
	this->frequency = 0.0;
	this->phase = 0;
}
SineWavetableOscillator::~SineWavetableOscillator(){}

long SineWavetableOscillator::nextSample() {
	int wavetableIndex = (int)((float)(this->phase*(float)WAVETABLE_SIZE)/((float)this->sampleRate));
	this->phase+=this->frequency;
	this->phase=fmod(this->phase,this->sampleRate);

	return sineTable[wavetableIndex];
}

void SineWavetableOscillator::setFrequency(float frequency) {
	this->frequency = frequency;
}
}






