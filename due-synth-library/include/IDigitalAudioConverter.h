
#ifndef INCLUDE_IDIGITALAUDIOCONVERTER_H_
#define INCLUDE_IDIGITALAUDIOCONVERTER_H_
#include <IAudioGenerator.h>

class IDigitalAudioConverter {
public:
	IDigitalAudioConverter(){};
	virtual void addAudioGeneratorToOutput(IAudioGenerator* generator)=0;
	virtual ~IDigitalAudioConverter(){};
};

#endif /* INCLUDE_IDIGITALAUDIOCONVERTER_H_ */
