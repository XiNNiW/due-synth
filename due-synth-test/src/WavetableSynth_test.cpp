#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <WavetableSynth.h>
#include <IWavetableOscillator.h>
#include <MockWavetableOscillator.h>
#include <SineWavetableOscillator.h>
#include <typeinfo>
using ::testing::Mock;

TEST(TestWavetableSynth, is_constructed_with_an_oscillator){
	IWavetableOscillator* expectedOscillator = new SineWavetableOscillator();
	WavetableSynth* synth = new WavetableSynth();
	IWavetableOscillator* actualOscillator = synth->oscillator;
	EXPECT_EQ(typeid(expectedOscillator).name(),typeid(actualOscillator).name());
}

TEST(TestWavetableSynth, is_calls_next_sample_on_osc_when_called){
	testing::StrictMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,nextSample()).Times(3);
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->nextSample();
	synth->nextSample();
	synth->nextSample();
}

