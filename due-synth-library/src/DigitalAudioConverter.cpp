#include <DigitalAudioConverter.h>
using namespace sunthesis;
DigitalAudioConverter* DigitalAudioConverter::singleton = 0;

DigitalAudioConverter::DigitalAudioConverter():IDigitalAudioConverter(){
	this->generator=0;
}

DigitalAudioConverter::~DigitalAudioConverter(){
	delete this->generator;
}

IDigitalAudioConverter* DigitalAudioConverter::instance(){
	if(!singleton){
		singleton = new DigitalAudioConverter();
	}
	return singleton;
}

long DigitalAudioConverter::nextSample(){
	if(!generator){
		return 0;
	}
	return this->generator->nextSample();

};

void DigitalAudioConverter::addAudioGeneratorToOutput(IAudioGenerator* generator){
	this->generator=generator;
}


