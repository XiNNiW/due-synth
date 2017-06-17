#include <gtest/gtest.h>
#include <Synthesis/SineWavetableOscillator.h>
using namespace sunthesis;
static long sineTable[128] = { 0, 100, 200, 300, 399, 497, 594, 689, 783, 875,
		965, 1052, 1137, 1219, 1299, 1375, 1448, 1517, 1583, 1644, 1702, 1756,
		1806, 1851, 1892, 1928, 1959, 1986, 2008, 2025, 2038, 2045, 2048, 2045,
		2038, 2025, 2008, 1986, 1959, 1928, 1892, 1851, 1806, 1756, 1702, 1644,
		1583, 1517, 1448, 1375, 1299, 1219, 1137, 1052, 965, 875, 783, 689, 594,
		497, 399, 300, 200, 100, 0, -100, -200, -300, -399, -497, -594, -689,
		-783, -875, -965, -1052, -1137, -1219, -1299, -1375, -1448, -1517,
		-1583, -1644, -1702, -1756, -1806, -1851, -1892, -1928, -1959, -1986,
		-2008, -2025, -2038, -2045, -2048, -2045, -2038, -2025, -2008, -1986,
		-1959, -1928, -1892, -1851, -1806, -1756, -1702, -1644, -1583, -1517,
		-1448, -1375, -1299, -1219, -1137, -1052, -965, -875, -783, -689, -594,
		-497, -399, -300, -200, -100 };

TEST(TestOscillatorNextSample, returns_every_sample_from_table_at_344HZ) {
	SineWavetableOscillator* oscillator = new SineWavetableOscillator();
	oscillator->setFrequency(344.53125f);

	for (int index = 0; index < 128; index++) {
		EXPECT_EQ(sineTable[index], oscillator->nextSample());
	}

}

TEST(TestOscillatorNextSample, returns_every_sample_from_table_at_100HZ) {

	int expectedSampleIndices[128] = { 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3,
			4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10,
			10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 15,
			15, 15, 15, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 19, 19, 19, 20,
			20, 20, 20, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 24, 24, 24, 24,
			25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 29,
			30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34,
			35, 35, 35, 35, 36, 36, 36};

	SineWavetableOscillator* oscillator = new SineWavetableOscillator();
	oscillator->setFrequency(100.0f);

	for (int index = 0; index < 128; index++) {
		EXPECT_EQ(sineTable[expectedSampleIndices[index]],
				oscillator->nextSample());
	}

}

TEST(TestOscillatorNextSample, returns_every_sample_from_table_at_1311HZ) {

	int expectedSampleIndices[141] = {
			0, 3, 7, 11, 15, 19, 22, 26, 30, 34, 38,
			41, 45, 49, 53, 57, 60, 64, 68, 72, 76, 79, 83, 87, 91, 95, 98, 102,
			106, 110, 114, 117, 121, 125, 1, 5, 8, 12, 16, 20, 24, 28, 31, 35,
			39, 43, 47, 50, 54, 58, 62, 66, 69, 73, 77, 81, 85, 88, 92, 96, 100,
			104, 107, 111, 115, 119, 123, 126, 2, 6, 10, 14, 17, 21, 25, 29, 33,
			36, 40, 44, 48, 52, 56, 59, 63, 67, 71, 75, 78, 82, 86, 90, 94, 97,
			101, 105, 109, 113, 116, 120, 124, 0, 4, 7, 11, 15, 19, 23, 26, 30,
			34, 38, 42, 45, 49, 53, 57, 61, 65, 68, 72, 76, 80, 84, 87, 91, 95,
			99, 103, 106, 110, 114, 118, 122, 125, 1, 5, 9, 13, 16, 20
	};

	SineWavetableOscillator* oscillator = new SineWavetableOscillator();
	oscillator->setFrequency(1311.0f);

	for (int index = 0; index < 141; index++) {
		EXPECT_EQ(sineTable[expectedSampleIndices[index]],
				oscillator->nextSample());
	}

}
