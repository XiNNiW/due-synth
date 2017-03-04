
#ifndef INCLUDE_DIGITALAUDIOCONVERTER_H_
#define INCLUDE_DIGITALAUDIOCONVERTER_H_
#include <IAudioGenerator.h>
#include <IDigitalAudioConverter.h>

class DigitalAudioConverter: public IDigitalAudioConverter{
private:
	static DigitalAudioConverter* singleton;
	DigitalAudioConverter();
public:
	void addAudioGeneratorToOutput(IAudioGenerator* generator);
	static IDigitalAudioConverter* instance();
	~DigitalAudioConverter();
};

#endif /* INCLUDE_DIGITALAUDIOCONVERTER_H_ */
