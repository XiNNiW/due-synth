#ifndef INCLUDE_IWAVETABLEOSCILLATOR_H_
#define INCLUDE_IWAVETABLEOSCILLATOR_H_ 1

class IWavetableOscillator {

public:
	IWavetableOscillator(){};
	virtual void setFrequency(float frequency)=0;
	virtual long nextSample()=0;
	virtual ~IWavetableOscillator(){};
};

#endif /* INCLUDE_IWAVETABLEOSCILLATOR_H_ */
