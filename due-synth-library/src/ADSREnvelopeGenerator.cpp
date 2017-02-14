#include "ADSREnvelopeGenerator.h"

ADSREnvelopeGenerator::ADSREnvelopeGenerator(float attack, float decay,
		float sustain, float release) {
	this->attack = attack;
	this->decay = decay;
	this->sustain = sustain;
	this->release = release;
	this->phase = 0;
	this->sampleRate = 44100;
	this->stage = OFF;

}

float ADSREnvelopeGenerator::advance() {

	switch (this->stage) {
	case ATTACK: {
		float attackTimeInSeconds = this->attack / 1000.0f;
		float numberOfSamplesInAttackPhase = ((float)this->sampleRate)
				* attackTimeInSeconds;
		float envelopeValue = (float) this->phase
				/ numberOfSamplesInAttackPhase;
		this->phase++;
		if (this->phase > numberOfSamplesInAttackPhase) {
			this->phase = 0;
			this->stage = DECAY;
		}
		return envelopeValue;
	}
	case DECAY: {
		float decayTimeInSeconds = this->decay / 1000.0f;
		float numberOfSamplesInDecayPhase =  ((float)this->sampleRate)
				* decayTimeInSeconds;
		float envelopeValue = 1.0f
				- (1.0f - this->sustain)
						* ((float) this->phase / numberOfSamplesInDecayPhase);
		this->phase++;
		if (this->phase > numberOfSamplesInDecayPhase) {
			this->phase = 0;
			this->stage = SUSTAIN;
		}
		return envelopeValue;
	}
	case SUSTAIN: {
		return this->sustain;
	}
	case RELEASE: {
		float numberOfSamplesInReleasePhase = ((float)this->sampleRate
				* this->release)/1000.0f;
		float envelopeValue = this->sustain*(1.0f - ((float) this->phase / numberOfSamplesInReleasePhase));
		this->phase++;
		if (this->phase > numberOfSamplesInReleasePhase) {
			this->phase = 0;
			this->stage = OFF;
		}
		return envelopeValue;
	}
	default: {
		return 0;
	}

	}

}

void ADSREnvelopeGenerator::start() {
	this->stage = ATTACK;
}
void ADSREnvelopeGenerator::stop() {
	this->stage = RELEASE;
}

ADSREnvelopeGenerator::~ADSREnvelopeGenerator() {
	// TODO Auto-generated destructor stub
}

