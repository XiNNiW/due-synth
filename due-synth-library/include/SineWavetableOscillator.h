#ifndef SRC_SINEWAVETABLEOSCILLATOR_H_
#define SRC_SINEWAVETABLEOSCILLATOR_H_

class SineWavetableOscillator {
public:
	SineWavetableOscillator();
	int nextSample();
	virtual ~SineWavetableOscillator();

};

#endif /* SRC_SINEWAVETABLEOSCILLATOR_H_ */
