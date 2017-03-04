#include <ArduinoDueLibraryWrapper.h>
#include "Arduino.h"

ArduinoDueLibraryWrapper* ArduinoDueLibraryWrapper::singleton = 0;
Tc* ArduinoDueLibraryWrapper::TIMER_CLOCK_ONE = TC1;
uint32_t ArduinoDueLibraryWrapper::TIMER_CLOCK_IER_CPCS = TC_IER_CPCS;

ArduinoDueLibraryWrapper* ArduinoDueLibraryWrapper::instance(){
	if(!singleton){
		ArduinoDueLibraryWrapper::singleton = new ArduinoDueLibraryWrapper();
	}
	return singleton;
};

ArduinoDueLibraryWrapper::ArduinoDueLibraryWrapper(){}
ArduinoDueLibraryWrapper::~ArduinoDueLibraryWrapper(){};

void ArduinoDueLibraryWrapper::pmcSetWriteProtect(bool writeProtectOn){
	pmc_set_writeprotect(writeProtectOn);
};

void ArduinoDueLibraryWrapper::pmcEnablePeripheralClock(IRQn_Type clockIdentifier){
	pmc_enable_periph_clk(clockIdentifier);
};

void ArduinoDueLibraryWrapper::configureTimerClock( Tc* clock, uint32_t dwChannel, uint32_t dwMode ){
	TC_Configure( clock, dwChannel,  dwMode );
};

void ArduinoDueLibraryWrapper::setRCOnTimerClock(Tc* tc, uint32_t chan, uint32_t v){
	TC_SetRC(tc, chan, v);
};

void ArduinoDueLibraryWrapper::startTimerClock( Tc* pTc, uint32_t dwChannel ){
	TC_Start(pTc, dwChannel );
};

uint32_t ArduinoDueLibraryWrapper::getStatusOfTimerClock(Tc *p_tc, uint32_t ul_channel){
	return TC_GetStatus(p_tc,ul_channel);
};

void ArduinoDueLibraryWrapper::enableNVICInterruptRequest(IRQn_Type counterIdentifier){
	NVIC_EnableIRQ(counterIdentifier);
};

void ArduinoDueLibraryWrapper::setPinMode(uint32_t ulPin, uint32_t ulMode){
	pinMode(ulPin,ulMode);
};

void ArduinoDueLibraryWrapper::setAnalogReadResolution(uint32_t resolutionInBits){
	analogReadResolution(resolutionInBits);
};

void ArduinoDueLibraryWrapper::setAnalogWriteResolution(uint32_t resolutionInBits){
	analogWriteResolution(resolutionInBits);
};

void ArduinoDueLibraryWrapper::setAnalogWrite(uint32_t ulPin, uint32_t ulValue){
	analogWrite(ulPin, ulValue);
};


