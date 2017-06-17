
#ifndef INCLUDE_DIGITALAUDIOCONVERTER_H_
#define INCLUDE_DIGITALAUDIOCONVERTER_H_
#include <IAudioGenerator.h>
#include <IDigitalAudioConverter.h>
namespace sunthesis{
class DigitalAudioConverter: public IDigitalAudioConverter{
private:
	static DigitalAudioConverter* singleton;
	DigitalAudioConverter();
	IAudioGenerator* generator;
public:
	static IDigitalAudioConverter* instance();
	virtual void addAudioGeneratorToOutput(IAudioGenerator* generator);
	virtual long nextSample();
	~DigitalAudioConverter();
};
}

#endif /* INCLUDE_DIGITALAUDIOCONVERTER_H_ */
