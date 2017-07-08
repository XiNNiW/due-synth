#ifndef SRC_SINEWAVETABLEOSCILLATOR_H_
#define SRC_SINEWAVETABLEOSCILLATOR_H_
#include <Synthesis/IWavetableOscillator.h>

namespace sunthesis{
class SineWavetableOscillator: virtual public IWavetableOscillator {

public:
	SineWavetableOscillator();
	virtual void setFrequency(float frequency);
	virtual sample nextSample();
	virtual ~SineWavetableOscillator();

protected:
	float phase;
	int sampleRate;
	float frequency;

};
}

#endif /* SRC_SINEWAVETABLEOSCILLATOR_H_ */
