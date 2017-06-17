#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Synthesis/IWavetableVoice.h>
#include <Synthesis/IWavetableOscillator.h>
#include <MockWavetableOscillator.h>
#include <Synthesis/SineWavetableOscillator.h>
#include <Synthesis/IEnvelopeGenerator.h>
#include <Synthesis/ADSREnvelopeGenerator.h>
#include <MockEnvelopeGenerator.h>
#include <Synthesis/WavetableVoice.h>
#include <typeinfo>
using ::testing::Mock;
using ::testing::FloatEq;
using ::testing::Return;

TEST(TestWavetableSynth, is_constructed_with_an_oscillator_and_envelope){
	IWavetableOscillator* expectedOscillator = new SineWavetableOscillator();
	IEnvelopeGenerator* expectedEnvelope = new ADSREnvelopeGenerator(0,0,0,0);
	WavetableVoice* synth = new WavetableVoice();
	IWavetableOscillator* actualOscillator = synth->oscillator;
	IEnvelopeGenerator* actualEnvelope = synth->envelope;
	EXPECT_EQ(typeid(expectedOscillator).name(),typeid(actualOscillator).name());
	EXPECT_EQ(typeid(expectedEnvelope).name(),typeid(actualEnvelope).name());
}

TEST(TestWavetableSynth, destructs_properly){
	MockWavetableOscillator* mockOscillator = new MockWavetableOscillator();
	MockEnvelopeGenerator* mockEnvelope = new MockEnvelopeGenerator();
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = mockOscillator;
	synth->envelope = mockEnvelope;
	EXPECT_CALL(*mockOscillator,Die());
	EXPECT_CALL(*mockEnvelope,Die());
	synth->~WavetableVoice();
	EXPECT_TRUE(Mock::VerifyAndClear(&*mockOscillator));
	EXPECT_TRUE(Mock::VerifyAndClear(&*mockEnvelope));
}

TEST(TestWavetableSynth, calls_next_sample_on_osc_when_called){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	testing::NiceMock<MockEnvelopeGenerator> mockEnvelope;
	EXPECT_CALL(mockOscillator,nextSample()).Times(3).WillRepeatedly(Return(5));
	EXPECT_CALL(mockEnvelope,advance()).Times(3).WillRepeatedly(Return(1.0));
	WavetableVoice* synth = new WavetableVoice();
	synth->envelope = &mockEnvelope;
	synth->oscillator = &mockOscillator;
	EXPECT_EQ(5,synth->nextSample());
	EXPECT_EQ(5,synth->nextSample());
	EXPECT_EQ(5,synth->nextSample());

}

TEST(TestWavetableSynth, multiplies_output_by_envelope){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	testing::NiceMock<MockEnvelopeGenerator> mockEnvelope;
	EXPECT_CALL(mockOscillator,nextSample()).Times(3).WillRepeatedly(Return(128));
	EXPECT_CALL(mockEnvelope,advance()).Times(3).WillRepeatedly(Return(0.5));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->envelope = &mockEnvelope;
	EXPECT_EQ(64,synth->nextSample());
	EXPECT_EQ(64,synth->nextSample());
	EXPECT_EQ(64,synth->nextSample());
}

TEST(TestWavetableSynth, multiplies_output_by_envelope_case_2){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	testing::NiceMock<MockEnvelopeGenerator> mockEnvelope;
	EXPECT_CALL(mockOscillator,nextSample()).Times(3).WillRepeatedly(Return(128));
	EXPECT_CALL(mockEnvelope,advance()).Times(3).WillRepeatedly(Return(0.0));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->envelope = &mockEnvelope;
	EXPECT_EQ(0,synth->nextSample());
	EXPECT_EQ(0,synth->nextSample());
	EXPECT_EQ(0,synth->nextSample());
}

TEST(TestWavetableSynth, play_with_non_zero_velocity_starts_envelope){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	testing::NiceMock<MockEnvelopeGenerator> mockEnvelope;
	EXPECT_CALL(mockEnvelope,start());
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->envelope = &mockEnvelope;
	synth->playNote(0, 100);
}

TEST(TestWavetableSynth, play_with_zero_velocity_stops_envelope){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	testing::NiceMock<MockEnvelopeGenerator> mockEnvelope;
	EXPECT_CALL(mockEnvelope,stop());
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->envelope = &mockEnvelope;
	synth->playNote(0, 0);
}

TEST(TestWavetableSynth, play_sets_frequency_of_osc_0){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(8.175799f)));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->playNote(0, 100);
}

TEST(TestWavetableSynth, play_sets_frequency_of_osc_60){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(261.62558f)));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->playNote(60, 100);
}

TEST(TestWavetableSynth, play_sets_frequency_of_osc_73){
	testing::NiceMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(554.365234f)));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->playNote(73, 100);
}

TEST(TestWavetableSynth, play_sets_frequency_of_osc_127){
	testing::StrictMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(12543.853516f)));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->playNote(127, 100);
}

TEST(TestWavetableSynth, play_sets_frequency_of_osc_neg5){
	testing::StrictMock<MockWavetableOscillator> mockOscillator;
	EXPECT_CALL(mockOscillator,setFrequency(FloatEq(6.124928f)));
	WavetableVoice* synth = new WavetableVoice();
	synth->oscillator = &mockOscillator;
	synth->playNote(-5, 100);
}



