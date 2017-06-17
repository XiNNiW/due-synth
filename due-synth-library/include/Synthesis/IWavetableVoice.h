
#ifndef INCLUDE_IWAVETABLEVOICE_H_
#define INCLUDE_IWAVETABLEVOICE_H_

#include <IAudioGenerator.h>

class IWavetableVoice: public IAudioGenerator {

public:
	IWavetableVoice(){};
	virtual ~IWavetableVoice(){};
	virtual void playNote(int noteNumber, int velocity)=0;
};

#endif /* INCLUDE_IWAVETABLEVOICE_H_ */
