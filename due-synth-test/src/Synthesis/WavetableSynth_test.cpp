#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Synthesis/IWavetableSynth.h>
#include <Synthesis/WavetableSynth.h>
#include <Synthesis/IWavetableOscillator.h>
#include <MockWavetableOscillator.h>
#include <Synthesis/SineWavetableOscillator.h>
#include <typeinfo>
using ::testing::Mock;
using ::testing::FloatEq;

TEST(TestWavetableSynth, is_constructed_with_an_oscillator){
	IWavetableOscillator* expectedOscillator = new SineWavetableOscillator();
	WavetableSynth* synth = new WavetableSynth();
	IWavetableOscillator* actualOscillator = synth->oscillator;
	EXPECT_EQ(typeid(expectedOscillator).name(),typeid(actualOscillator).name());
}

TEST(TestWavetableSynth, is_calls_next_sample_on_osc_when_called){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,nextSample()).Times(3);
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->nextSample();
	synth->nextSample();
	synth->nextSample();
}

TEST(TestWavetableSynth, has_a_play_sets_frequency_of_osc_0){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(8.175799f)));
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->playNote(0, 100);
}

TEST(TestWavetableSynth, has_a_play_sets_frequency_of_osc_60){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(261.62558f)));
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->playNote(60, 100);
}

TEST(TestWavetableSynth, has_a_play_sets_frequency_of_osc_73){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(554.365234f)));
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->playNote(73, 100);
}

TEST(TestWavetableSynth, has_a_play_sets_frequency_of_osc_127){
	testing::StrictMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(12543.853516f)));
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->playNote(127, 100);
}

TEST(TestWavetableSynth, has_a_play_sets_frequency_of_osc_neg5){
	testing::StrictMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(6.124928f)));
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = &mockOscillator;
	synth->playNote(-5, 100);
}

