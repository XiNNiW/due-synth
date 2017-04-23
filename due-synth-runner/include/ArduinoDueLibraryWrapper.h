#ifndef ARDUINODUELIBRARYWRAPPER_H_
#define ARDUINODUELIBRARYWRAPPER_H_
#include "Arduino.h"

class ArduinoDueLibraryWrapper{
private:
	static ArduinoDueLibraryWrapper* singleton;
	ArduinoDueLibraryWrapper();
public:
	enum InterruptType{TIMER_CLOCK_FOUR_IRQn=ID_TC4};
	enum ClockIdentifier{
		TIMER_CLOCK_ONE,
		TIMER_CLOCK_TWO,
		TIMER_CLOCK_THREE,
		TIMER_CLOCK_FOUR
	};

	static ArduinoDueLibraryWrapper* instance();
	virtual ~ArduinoDueLibraryWrapper();

	virtual void pmcSetWriteProtect(bool writeProtectOn);
	virtual void pmcEnablePeripheralClock(InterruptType counterIdentifier);

	virtual void configureTimerClock( Tc* clock, uint32_t dwChannel, uint32_t dwMode );
	virtual void setRCOnTimerClock(Tc* tc, uint32_t chan, uint32_t v);
	virtual void startTimerClock( Tc* pTc, uint32_t dwChannel );
	virtual uint32_t getStatusOfTimerClock(Tc *p_tc, uint32_t ul_channel);
	virtual void enableNVICInterruptRequest(InterruptType counterIdentifier);
	virtual void setPinMode(uint32_t ulPin, uint32_t ulMode);
	virtual void setAnalogReadResolution(uint32_t resolutionInBits);
	virtual void setAnalogWriteResolution(uint32_t resolutionInBits);
	virtual void setAnalogWrite(uint32_t ulPin, uint32_t ulValue);

//	// enable timer interrupts on the timer
//	TC1->TC_CHANNEL[1].TC_IER=TC_IER_CPCS;
//	TC1->TC_CHANNEL[1].TC_IDR=~TC_IER_CPCS;
//
////	TC_GetStatus(TC1, 1);
};


#endif /* ARDUINODUELIBRARYWRAPPER_H_ */
