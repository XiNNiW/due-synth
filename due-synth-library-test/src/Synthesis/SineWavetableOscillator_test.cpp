#include <gtest/gtest.h>
#include <Synthesis/SineWavetableOscillator.h>
#include <math.h>
#define WAVE_TABLE_SIZE 128
using namespace sunthesis;


sample sineTable[WAVE_TABLE_SIZE] = {32767,34375,35979,37575,39160,40729,42279,43806,45307,46777,48213,49613,50972,52287,53554,54772,55937,57046,58097,59086,60012,60873,61665,62388,63040,63619,64124,64552,64905,65180,65377,65495,65535,65495,65377,65180,64905,64552,64124,63619,63040,62388,61665,60873,60012,59086,58097,57046,55937,54772,53554,52287,50972,49613,48213,46777,45307,43806,42279,40729,39160,37575,35979,34375,32767,31159,29555,27959,26374,24805,23255,21728,20227,18757,17321,15921,14562,13247,11980,10762,9597,8488,7437,6448,5522,4661,3869,3146,2494,1915,1410,982,629,354,157,39,0,39,157,354,629,982,1410,1915,2494,3146,3869,4661,5522,6448,7437,8488,9597,10762,11980,13247,14562,15921,17321,18757,20227,21728,23255,24805,26374,27959,29555,31159};


void createSineTable()
{
  for(sample nIndex = 0;nIndex < WAVE_TABLE_SIZE;nIndex++)
  {
	  sineTable[nIndex] = (sample)  (((1+sin(((2.0*M_PI)/WAVE_TABLE_SIZE)*nIndex))*65535.0)/2);
	  printf("%d,",sineTable[nIndex]);


  }
}

TEST(TestOscillatorNextSample, returns_every_sample_from_table_at_344HZ) {
	createSineTable();
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
