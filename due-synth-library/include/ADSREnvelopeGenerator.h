/*
 * ADSREnvelopeGenerator.h
 *
 *  Created on: Feb 6, 2017
 *      Author: davidminnix
 */

#ifndef SRC_ADSRENVELOPEGENERATOR_H_
#define SRC_ADSRENVELOPEGENERATOR_H_

class ADSREnvelopeGenerator {
public:
	ADSREnvelopeGenerator(float attack,float decay, float sustain, float release);
	virtual ~ADSREnvelopeGenerator();
	float getCurrentValue();
	float attack;
	float decay;
	float sustain;
	float release;

};

#endif /* SRC_ADSRENVELOPEGENERATOR_H_ */
