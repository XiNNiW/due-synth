#include <DigitalAudioConverter.h>
#include <MockWavetableOscillator.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::Mock;


TEST(TestDigitalAudioConverter, is_a_singleton){
	IDigitalAudioConverter* dac1 = DigitalAudioConverter::instance();
	IDigitalAudioConverter* dac2 = DigitalAudioConverter::instance();

	EXPECT_EQ(dac1,dac2);
}

TEST(TestDigitalAudioConverter, can_add_audio_generators_to_output){
	IDigitalAudioConverter* dac = DigitalAudioConverter::instance();
	MockWavetableOscillator* mockGenerator = new MockWavetableOscillator();
	long expectedSample = 5;
	dac->addAudioGeneratorToOutput(mockGenerator);

	EXPECT_CALL(*mockGenerator,nextSample()).WillOnce(testing::Return(expectedSample));
	long actualSample = dac->nextSample();

	EXPECT_EQ(expectedSample,actualSample);
	EXPECT_TRUE(Mock::VerifyAndClear(&*mockGenerator));
	dac->~IDigitalAudioConverter();

}

TEST(TestDigitalAudioConverter, evaluating_next_sample_with_no_generators_gets_zero){
	IDigitalAudioConverter* dac = DigitalAudioConverter::instance();
	long expectedSample = 0;

	MockWavetableOscillator* mockGenerator = new MockWavetableOscillator();
	dac->addAudioGeneratorToOutput(mockGenerator);

	EXPECT_NO_FATAL_FAILURE(dac->nextSample());

	EXPECT_EQ(expectedSample,dac->nextSample());
}

TEST(TestDigitalAudioConverter, destructor){
	IDigitalAudioConverter* dac = DigitalAudioConverter::instance();
	MockWavetableOscillator* mockGenerator = new MockWavetableOscillator();
	dac->addAudioGeneratorToOutput(mockGenerator);

	EXPECT_CALL(*mockGenerator,Die());
	dac->~IDigitalAudioConverter();
	EXPECT_TRUE(Mock::VerifyAndClear(&*mockGenerator));
}
