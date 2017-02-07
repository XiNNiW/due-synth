#include <gtest/gtest.h>
#include <ADSREnvelopeGenerator.h>

TEST(TestADSREnvelopeGenerator, initialized_with_attack_decay_sustain_release_in_millis){
	float expectedAttackTime = 50.0f;
	float expectedDecayTime = 100.0f;
	float expectedSustainLevel = 0.5f;
	float expectedReleaseTime = 500.0f;

	ADSREnvelopeGenerator* envelope = new ADSREnvelopeGenerator(expectedAttackTime,
			expectedDecayTime, expectedSustainLevel, expectedReleaseTime);

	EXPECT_EQ(expectedAttackTime,envelope->attack);
	EXPECT_EQ(expectedDecayTime,envelope->decay);
	EXPECT_EQ(expectedSustainLevel,envelope->sustain);
	EXPECT_EQ(expectedReleaseTime,envelope->release);

};

TEST(TestADSREnvelopeGenerator, advances_through_stages_when_started_and_stopped){
	float expectedAttackTime = 50.0f;
	float expectedDecayTime = 100.0f;
	float expectedSustainLevel = 0.5f;
	float expectedReleaseTime = 500.0f;

	ADSREnvelopeGenerator* envelope = new ADSREnvelopeGenerator(expectedAttackTime,
			expectedDecayTime, expectedSustainLevel, expectedReleaseTime);

	EXPECT_EQ(expectedAttackTime,envelope->attack);
	EXPECT_EQ(expectedDecayTime,envelope->decay);
	EXPECT_EQ(expectedSustainLevel,envelope->sustain);
	EXPECT_EQ(expectedReleaseTime,envelope->release);

	EXPECT_EQ(1.0f,envelope->getCurrentValue());

//	envelope->start();
//
//
//
//	envelope->stop();

};

