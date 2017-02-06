#ifndef INCLUDE_MOCKWAVETABLEOSCILLATOR_H_
#define INCLUDE_MOCKWAVETABLEOSCILLATOR_H_
#include <gmock/gmock.h>
#include <IWavetableOscillator.h>

class MockWavetableOscillator : public IWavetableOscillator {
public:
	MockWavetableOscillator();
	~MockWavetableOscillator();
	MOCK_METHOD0(nextSample,long());
	MOCK_METHOD1(setFrequency,void(float f));
};

#endif /* INCLUDE_MOCKWAVETABLEOSCILLATOR_H_ */