#include <gtest/gtest.h>
#include <ADSREnvelopeGenerator.h>

static float attackDecayValueTable[128] = { 0, 0.007874015748, 0.0157480315,
		0.02362204724, 0.03149606299, 0.03937007874, 0.04724409449,
		0.05511811024, 0.06299212598, 0.07086614173, 0.07874015748,
		0.08661417323, 0.09448818898, 0.1023622047, 0.1102362205, 0.1181102362,
		0.125984252, 0.1338582677, 0.1417322835, 0.1496062992, 0.157480315,
		0.1653543307, 0.1732283465, 0.1811023622, 0.188976378, 0.1968503937,
		0.2047244094, 0.2125984252, 0.2204724409, 0.2283464567, 0.2362204724,
		0.2440944882, 0.2519685039, 0.2598425197, 0.2677165354, 0.2755905512,
		0.2834645669, 0.2913385827, 0.2992125984, 0.3070866142, 0.3149606299,
		0.3228346457, 0.3307086614, 0.3385826772, 0.3464566929, 0.3543307087,
		0.3622047244, 0.3700787402, 0.3779527559, 0.3858267717, 0.3937007874,
		0.4015748031, 0.4094488189, 0.4173228346, 0.4251968504, 0.4330708661,
		0.4409448819, 0.4488188976, 0.4566929134, 0.4645669291, 0.4724409449,
		0.4803149606, 0.4881889764, 0.4960629921, 0.5039370079, 0.5118110236,
		0.5196850394, 0.5275590551, 0.5354330709, 0.5433070866, 0.5511811024,
		0.5590551181, 0.5669291339, 0.5748031496, 0.5826771654, 0.5905511811,
		0.5984251969, 0.6062992126, 0.6141732283, 0.6220472441, 0.6299212598,
		0.6377952756, 0.6456692913, 0.6535433071, 0.6614173228, 0.6692913386,
		0.6771653543, 0.6850393701, 0.6929133858, 0.7007874016, 0.7086614173,
		0.7165354331, 0.7244094488, 0.7322834646, 0.7401574803, 0.7480314961,
		0.7559055118, 0.7637795276, 0.7716535433, 0.7795275591, 0.7874015748,
		0.7952755906, 0.8031496063, 0.811023622, 0.8188976378, 0.8267716535,
		0.8346456693, 0.842519685, 0.8503937008, 0.8582677165, 0.8661417323,
		0.874015748, 0.8818897638, 0.8897637795, 0.8976377953, 0.905511811,
		0.9133858268, 0.9212598425, 0.9291338583, 0.937007874, 0.9448818898,
		0.9527559055, 0.9606299213, 0.968503937, 0.9763779528, 0.9842519685,
		0.9921259843, 1 };

TEST(TestADSREnvelopeGenerator, initialized_with_attack_decay_sustain_release_in_millis) {
	float expectedAttackTime = 50.0f;
	float expectedDecayTime = 100.0f;
	float expectedSustainLevel = 0.5f;
	float expectedReleaseTime = 500.0f;

	ADSREnvelopeGenerator* envelope = new ADSREnvelopeGenerator(
			expectedAttackTime, expectedDecayTime, expectedSustainLevel,
			expectedReleaseTime);

	EXPECT_EQ(expectedAttackTime, envelope->attack);
	EXPECT_EQ(expectedDecayTime, envelope->decay);
	EXPECT_EQ(expectedSustainLevel, envelope->sustain);
	EXPECT_EQ(expectedReleaseTime, envelope->release);
	EXPECT_EQ(44100, envelope->sampleRate);

}
;

TEST(TestADSREnvelopeGenerator, advances_through_stages_when_started_and_stopped_CASE1) {

	const int numberOfAttackSamples = 89;
	int expectedAttackPhaseIndices[numberOfAttackSamples] = { 0, 1, 2, 4, 5, 7,
			8, 10, 11, 13, 14, 15, 17, 18, 20, 21, 23, 24, 26, 27, 29, 30, 31,
			33, 34, 36, 37, 39, 40, 42, 43, 44, 46, 47, 49, 50, 52, 53, 55, 56,
			58, 59, 60, 62, 63, 65, 66, 68, 69, 71, 72, 74, 75, 76, 78, 79, 81,
			82, 84, 85, 87, 88, 89, 91, 92, 94, 95, 97, 98, 100, 101, 103, 104,
			105, 107, 108, 110, 111, 113, 114, 116, 117, 119, 120, 121, 123,
			124, 126, 127 };


	float expectedAttackTime = 50.0f;
	float expectedDecayTime = 100.0f;
	float expectedSustainLevel = 0.5f;
	float expectedReleaseTime = 500.0f;

	ADSREnvelopeGenerator* envelope = new ADSREnvelopeGenerator(
			expectedAttackTime, expectedDecayTime, expectedSustainLevel,
			expectedReleaseTime);

	EXPECT_EQ(expectedAttackTime, envelope->attack);
	EXPECT_EQ(expectedDecayTime, envelope->decay);
	EXPECT_EQ(expectedSustainLevel, envelope->sustain);
	EXPECT_EQ(expectedReleaseTime, envelope->release);

	envelope->start();
	for (int index = 0; index < numberOfAttackSamples; index++) {
		EXPECT_EQ(attackDecayValueTable[expectedAttackPhaseIndices[index]],
				envelope->advance());
	}

//	for (int index = numberOfDecaySamples; index > 0; index++) {
//		EXPECT_EQ(attackDecayValueTable[expectedAttackPhaseIndices[index]],
//				envelope->advance());
//	}

	envelope->stop();

};

//TEST(TestADSREnvelopeGenerator, advances_through_stages_when_started_and_stopped_CASE2) {
//
//	const int numberOfAttackSamples = 326;
//	int expectedAttackPhaseIndices[numberOfAttackSamples] = { 0, 0, 0, 1, 1, 2,
//			2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9, 10, 10, 11,
//			11, 12, 12, 12, 13, 13, 14, 14, 14, 15, 15, 16, 16, 17, 17, 17, 18,
//			18, 19, 19, 19, 20, 20, 21, 21, 21, 22, 22, 23, 23, 24, 24, 24, 25,
//			25, 26, 26, 26, 27, 27, 28, 28, 29, 29, 29, 30, 30, 31, 31, 31, 32,
//			32, 33, 33, 34, 34, 34, 35, 35, 36, 36, 36, 37, 37, 38, 38, 38, 39,
//			39, 40, 40, 41, 41, 41, 42, 42, 43, 43, 43, 44, 44, 45, 45, 46, 46,
//			46, 47, 47, 48, 48, 48, 49, 49, 50, 50, 51, 51, 51, 52, 52, 53, 53,
//			53, 54, 54, 55, 55, 55, 56, 56, 57, 57, 58, 58, 58, 59, 59, 60, 60,
//			60, 61, 61, 62, 62, 63, 63, 63, 64, 64, 65, 65, 65, 66, 66, 67, 67,
//			68, 68, 68, 69, 69, 70, 70, 70, 71, 71, 72, 72, 72, 73, 73, 74, 74,
//			75, 75, 75, 76, 76, 77, 77, 77, 78, 78, 79, 79, 80, 80, 80, 81, 81,
//			82, 82, 82, 83, 83, 84, 84, 85, 85, 85, 86, 86, 87, 87, 87, 88, 88,
//			89, 89, 89, 90, 90, 91, 91, 92, 92, 92, 93, 93, 94, 94, 94, 95, 95,
//			96, 96, 97, 97, 97, 98, 98, 99, 99, 99, 100, 100, 101, 101, 102,
//			102, 102, 103, 103, 104, 104, 104, 105, 105, 106, 106, 106, 107,
//			107, 108, 108, 109, 109, 109, 110, 110, 111, 111, 111, 112, 112,
//			113, 113, 114, 114, 114, 115, 115, 116, 116, 116, 117, 117, 118,
//			118, 119, 119, 119, 120, 120, 121, 121, 121, 122, 122, 123, 123,
//			123, 124, 124, 125, 125, 126, 126, 126, 127, 127, 0, 0, 0, 1, 1, 2,
//			2, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6, };
//
//
//	float expectedAttackTime = 50.0f;
//	float expectedDecayTime = 100.0f;
//	float expectedSustainLevel = 0.5f;
//	float expectedReleaseTime = 500.0f;
//
//	ADSREnvelopeGenerator* envelope = new ADSREnvelopeGenerator(
//			expectedAttackTime, expectedDecayTime, expectedSustainLevel,
//			expectedReleaseTime);
//
//	EXPECT_EQ(expectedAttackTime, envelope->attack);
//	EXPECT_EQ(expectedDecayTime, envelope->decay);
//	EXPECT_EQ(expectedSustainLevel, envelope->sustain);
//	EXPECT_EQ(expectedReleaseTime, envelope->release);
//
//	envelope->start();
//	for (int index = 0; index < numberOfAttackSamples; index++) {
//		EXPECT_EQ(attackDecayValueTable[expectedAttackPhaseIndices[index]],
//				envelope->advance());
//	}
//
//
//	envelope->stop();
//
//};
