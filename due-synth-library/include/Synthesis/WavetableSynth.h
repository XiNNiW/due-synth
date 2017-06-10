
#ifndef SRC_WAVETABLESYNTH_H_
#define SRC_WAVETABLESYNTH_H_
#include <Synthesis/IWavetableSynth.h>
#include <Synthesis/IWavetableOscillator.h>
#include <Synthesis/IEnvelopeGenerator.h>
#include <IAudioGenerator.h>

class WavetableSynth : public IWavetableSynth, virtual IAudioGenerator{

public:
	WavetableSynth();
	virtual ~WavetableSynth();
	virtual long nextSample();
	virtual void playNote(int noteNumber, int velocity);
	IWavetableOscillator* oscillator;
	IEnvelopeGenerator* envelope;
};

#endif /* SRC_WAVETABLESYNTH_H_ */
