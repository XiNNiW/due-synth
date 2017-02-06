
#ifndef SRC_WAVETABLESYNTH_H_
#define SRC_WAVETABLESYNTH_H_
#include <IWavetableSynth.h>
#include <IWavetableOscillator.h>
#include <IAudioGenerator.h>

class WavetableSynth : public IWavetableSynth, virtual IAudioGenerator{

public:
	WavetableSynth();
	virtual ~WavetableSynth();
	virtual long nextSample();
	virtual void playNote(int noteNumber, int velocity);
	IWavetableOscillator* oscillator;
};

#endif /* SRC_WAVETABLESYNTH_H_ */
