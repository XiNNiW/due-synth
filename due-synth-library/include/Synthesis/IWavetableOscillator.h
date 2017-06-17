#ifndef INCLUDE_IWAVETABLEOSCILLATOR_H_
#define INCLUDE_IWAVETABLEOSCILLATOR_H_ 1

#include <IAudioGenerator.h>
namespace sunthesis{
class IWavetableOscillator : virtual public IAudioGenerator {

public:
	IWavetableOscillator(){};
	virtual void setFrequency(float frequency)=0;
	virtual long nextSample()=0;
	virtual ~IWavetableOscillator(){};
};
}

#endif /* INCLUDE_IWAVETABLEOSCILLATOR_H_ */
