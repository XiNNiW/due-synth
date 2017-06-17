
#ifndef SRC_WAVETABLEVOICE_H_
#define SRC_WAVETABLEVOICE_H_
#include <Synthesis/IWavetableVoice.h>
#include <Synthesis/IWavetableOscillator.h>
#include <Synthesis/IEnvelopeGenerator.h>
#include <IAudioGenerator.h>

class WavetableVoice : public IWavetableVoice, virtual IAudioGenerator{

public:
	WavetableVoice();
	virtual ~WavetableVoice();
	virtual long nextSample();
	virtual void playNote(int noteNumber, int velocity);
	IWavetableOscillator* oscillator;
	IEnvelopeGenerator* envelope;
};

#endif /* SRC_WAVETABLEVOICE_H_ */
