/*
 * IArduinoLibraryWrapper.h
 *
 *  Created on: Mar 3, 2017
 *      Author: davidminnix
 */

#ifndef INCLUDE_IARDUINOLIBRARYWRAPPER_H_
#define INCLUDE_IARDUINOLIBRARYWRAPPER_H_

#include <Arduino.h>

class IArduinoDueLibraryWrapper{
public:
	IArduinoDueLibraryWrapper(){};
	virtual ~IArduinoDueLibraryWrapper();
	virtual void pmc_set_writeprotect(bool writeProtectOn);
	virtual void pmc_enable_periph_clk(int counterIdentifier);


	virtual void TC_Configure( Tc* clock, uint32_t dwChannel, uint32_t dwMode );

	virtual void TC_SetRC(Tc* tc, uint32_t chan, uint32_t v);

	virtual void TC_Start( Tc* pTc, uint32_t dwChannel );

	virtual uint32_t TC_GetStatus(Tc *p_tc, uint32_t ul_channel);

	virtual void NVIC_EnableIRQ(uint32_t counterIdentifier);

	virtual void pinMode(uint32_t ulPin, uint32_t ulMode);
	virtual void analogReadResolution(uint32_t resolutionInBits);
	virtual void analogWriteResolution(uint32_t resolutionInBits);
	virtual void analogWrite(uint32_t ulPin, uint32_t ulValue);
};


#endif /* INCLUDE_IARDUINOLIBRARYWRAPPER_H_ */
