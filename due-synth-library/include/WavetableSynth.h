
#ifndef SRC_WAVETABLESYNTH_H_
#define SRC_WAVETABLESYNTH_H_
#include <IWavetableOscillator.h>

class WavetableSynth {

public:
	WavetableSynth();
	virtual ~WavetableSynth();
	virtual long nextSample();
	IWavetableOscillator* oscillator;
};

#endif /* SRC_WAVETABLESYNTH_H_ */
