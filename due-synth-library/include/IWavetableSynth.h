
#ifndef INCLUDE_IWAVETABLESYNTH_H_
#define INCLUDE_IWAVETABLESYNTH_H_

class IWavetableSynth {

public:
	IWavetableSynth(){};
	virtual ~IWavetableSynth(){};
	virtual void playNote(int noteNumber, int velocity)=0;
};

#endif /* INCLUDE_IWAVETABLESYNTH_H_ */