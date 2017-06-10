#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Synthesis/IWavetableSynth.h>
#include <Synthesis/WavetableSynth.h>
#include <Synthesis/IWavetableOscillator.h>
#include <MockWavetableOscillator.h>
#include <Synthesis/SineWavetableOscillator.h>
#include <Synthesis/IEnvelopeGenerator.h>
#include <Synthesis/ADSREnvelopeGenerator.h>
#include <MockEnvelopeGenerator.h>
#include <typeinfo>
using ::testing::Mock;
using ::testing::FloatEq;

TEST(TestWavetableSynth, is_constructed_with_an_oscillator_and_envelope){
	IWavetableOscillator* expectedOscillator = new SineWavetableOscillator();
	IEnvelopeGenerator* expectedEnvelope = new ADSREnvelopeGenerator(0,0,0,0);
	WavetableSynth* synth = new WavetableSynth();
	IWavetableOscillator* actualOscillator = synth->oscillator;
	IEnvelopeGenerator* actualEnvelope = synth->envelope;
	EXPECT_EQ(typeid(expectedOscillator).name(),typeid(actualOscillator).name());
	EXPECT_EQ(typeid(expectedEnvelope).name(),typeid(actualEnvelope).name());
}

TEST(TestWavetableSynth, destructs_properly){
	MockWavetableOscillator* mockOscillator = new MockWavetableOscillator();
	MockEnvelopeGenerator* mockEnvelope = new MockEnvelopeGenerator();
	WavetableSynth* synth = new WavetableSynth();
	synth->oscillator = mockOscillator;
	synth->envelope = mockEnvelope;
	EXPECT_CALL(*mockOscillator,Die());
	EXPECT_CALL(*mockEnvelope,Die());
	synth->~WavetableSynth();
	EXPECT_TRUE(Mock::VerifyAndClear(&*mockOscillator));
	EXPECT_TRUE(Mock::VerifyAndClear(&*mockEnvelope));
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



