#include <gtest/gtest.h>
#include <SineWavetableOscillator.h>


TEST(TestOscillatorNextSample, returns_zero) {
	SineWavetableOscillator* oscillator = new SineWavetableOscillator();
	EXPECT_EQ(0, oscillator->nextSample());
}
