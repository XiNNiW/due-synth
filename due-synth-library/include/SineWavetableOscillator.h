#ifndef SRC_SINEWAVETABLEOSCILLATOR_H_
#define SRC_SINEWAVETABLEOSCILLATOR_H_
#include "IWavetableOscillator.h"


class SineWavetableOscillator: public IWavetableOscillator {

public:
	SineWavetableOscillator();
	virtual void setFrequency(float frequency);
	virtual long nextSample();
	virtual ~SineWavetableOscillator();

protected:
	float phase;
	int sampleRate;
	float frequency;

};

#endif /* SRC_SINEWAVETABLEOSCILLATOR_H_ */
