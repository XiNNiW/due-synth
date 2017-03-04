#include <DigitalAudioConverter.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


TEST(TestDigitalAudioConverter, is_a_singleton){
	IDigitalAudioConverter* dac1 = DigitalAudioConverter::instance();
	IDigitalAudioConverter* dac2 = DigitalAudioConverter::instance();

	EXPECT_EQ(dac1,dac2);

}

TEST(TestDigitalAudioConverter, starts_sample_rate_timer_on_init){}

TEST(TestDigitalAudioConverter, can_add_audio_generators_to_output){}
