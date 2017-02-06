#ifndef SRC_SINEWAVETABLEOSCILLATOR_H_
#define SRC_SINEWAVETABLEOSCILLATOR_H_

class SineWavetableOscillator {

public:
	SineWavetableOscillator();
	void setFrequency(float frequency);
	int nextSample();
	virtual ~SineWavetableOscillator();

protected:
	float phase;
	int sampleRate;
	float frequency;

};

#endif /* SRC_SINEWAVETABLEOSCILLATOR_H_ */
