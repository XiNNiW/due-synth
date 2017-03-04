#include <DigitalAudioConverter.h>
DigitalAudioConverter* DigitalAudioConverter::singleton = 0;
DigitalAudioConverter::DigitalAudioConverter():IDigitalAudioConverter(){

}

DigitalAudioConverter::~DigitalAudioConverter(){

}



IDigitalAudioConverter* DigitalAudioConverter::instance(){
	if(!singleton){
		singleton = new DigitalAudioConverter();
	}
	return singleton;
}

void DigitalAudioConverter::addAudioGeneratorToOutput(IAudioGenerator* generator){

}


