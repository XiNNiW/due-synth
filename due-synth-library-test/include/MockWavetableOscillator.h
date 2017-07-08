#ifndef INCLUDE_MOCKWAVETABLEOSCILLATOR_H_
#define INCLUDE_MOCKWAVETABLEOSCILLATOR_H_
#include <gmock/gmock.h>
#include <Synthesis/IWavetableOscillator.h>
#include <CommonTypes.h>
using namespace sunthesis;
class MockWavetableOscillator : public IWavetableOscillator {
public:
	MockWavetableOscillator();
	~MockWavetableOscillator(){Die();};
	MOCK_METHOD0(Die,void());
	MOCK_METHOD0(nextSample,sample());
	MOCK_METHOD1(setFrequency,void(float f));
};

#endif /* INCLUDE_MOCKWAVETABLEOSCILLATOR_H_ */
