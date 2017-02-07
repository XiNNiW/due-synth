#include "ADSREnvelopeGenerator.h"

ADSREnvelopeGenerator::ADSREnvelopeGenerator(
		float attack,
		float decay,
		float sustain,
		float release)
{
	this->attack = attack;
	this->decay = decay;
	this->sustain = sustain;
	this->release = release;

}

float ADSREnvelopeGenerator::getCurrentValue(){
	return 0.0f;
}

ADSREnvelopeGenerator::~ADSREnvelopeGenerator() {
	// TODO Auto-generated destructor stub
}

