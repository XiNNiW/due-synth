/*
 * ADSREnvelopeGenerator.h
 *
 *  Created on: Feb 6, 2017
 *      Author: davidminnix
 */

#ifndef SRC_ADSRENVELOPEGENERATOR_H_
#define SRC_ADSRENVELOPEGENERATOR_H_

#include <Synthesis/IEnvelopeGenerator.h>

enum EnvelopeStages {OFF,ATTACK,DECAY,SUSTAIN,RELEASE};

class ADSREnvelopeGenerator: public IEnvelopeGenerator{
public:
	ADSREnvelopeGenerator(float attack,float decay, float sustain, float release);
	virtual ~ADSREnvelopeGenerator();
	float advance();
	void start();
	void stop();
	float attack;
	float decay;
	float sustain;
	float release;
	int sampleRate;
	EnvelopeStages stage;
private:
	int phase;
	static const int ATTACK_TABLE_SIZE = 128;

};

#endif /* SRC_ADSRENVELOPEGENERATOR_H_ */
