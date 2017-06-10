#ifndef INCLUDE_MOCKWAVETABLEOSCILLATOR_H_
#define INCLUDE_MOCKWAVETABLEOSCILLATOR_H_
#include "Arduino.h"
#include <gmock/gmock.h>
#include <ArduinoDueLibraryWrapper.h>
//#include "component_tc.h"

class MockArduinoDueLibraryWrapper : public ArduinoDueLibraryWrapper {
public:
	MockArduinoDueLibraryWrapper();
	~MockArduinoDueLibraryWrapper();
	MOCK_METHOD1(pmcSetWriteProtect, void(bool b));
	MOCK_METHOD1(pmcEnablePeripheralClock, void(InterruptType c));
	//MOCK_METHOD3(configureTimerClock, void(Tc* clockId, uint32_t chan, uint32_t v));
//	MOCK_METHOD3(setRCOnTimerClock, void(ClockIdentifier clockId, uint32_t chan, uint32_t v));
//	MOCK_METHOD2(startTimerClock, void(ClockIdentifier clockId, uint32_t dwChannel));
//	MOCK_METHOD2(getStatusOfTimerClock, uint32_t(ClockIdentifier clockId, uint32_t ul_channel));
	MOCK_METHOD1(enableNVICInterruptRequest, void(InterruptType c));
	MOCK_METHOD2(setPinMode, void(uint32_t ulPin, uint32_t ulMode));
	MOCK_METHOD1(setAnalogReadResolution, void(uint32_t resolutionInBits));
	MOCK_METHOD1(setAnalogWriteResolution, void(uint32_t resolutionInBits));
	MOCK_METHOD2(setAnalogWrite, void(uint32_t ulPin, uint32_t ulValue));
};
#endif /* INCLUDE_MOCKWAVETABLEOSCILLATOR_H_ */

/*
  	static Tc* TIMER_CLOCK_ONE;
	static uint32_t TIMER_CLOCK_IER_CPCS;
	static ArduinoDueLibraryWrapper* instance();
	virtual ~ArduinoDueLibraryWrapper();

	virtual void pmcSetWriteProtect(bool writeProtectOn);
	virtual void pmcEnablePeripheralClock(IRQn_Type counterIdentifier);

	virtual void configureTimerClock( Tc* clock, uint32_t dwChannel, uint32_t dwMode );
	virtual void setRCOnTimerClock(Tc* tc, uint32_t chan, uint32_t v);
	virtual void startTimerClock( Tc* pTc, uint32_t dwChannel );
	virtual uint32_t getStatusOfTimerClock(Tc *p_tc, uint32_t ul_channel);
	virtual void enableNVICInterruptRequest(IRQn_Type counterIdentifier);
	virtual void setPinMode(uint32_t ulPin, uint32_t ulMode);
	virtual void setAnalogReadResolution(uint32_t resolutionInBits);
	virtual void setAnalogWriteResolution(uint32_t resolutionInBits);
	virtual void setAnalogWrite(uint32_t ulPin, uint32_t ulValue);
 */
