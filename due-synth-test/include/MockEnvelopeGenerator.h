/*
 * MockEnvelopeGenerator.h
 *
 *  Created on: Jun 7, 2017
 *      Author: davidminnix
 */

#ifndef INCLUDE_MOCKENVELOPEGENERATOR_H_
#define INCLUDE_MOCKENVELOPEGENERATOR_H_

#include <gmock/gmock.h>
#include <Synthesis/IEnvelopeGenerator.h>

class MockEnvelopeGenerator : public IEnvelopeGenerator {
public:
	MockEnvelopeGenerator();
	~MockEnvelopeGenerator(){Die();};
	MOCK_METHOD0(Die,void());
	MOCK_METHOD0(advance,float());
	MOCK_METHOD0(start,void());
	MOCK_METHOD0(stop,void());
};



#endif /* INCLUDE_MOCKENVELOPEGENERATOR_H_ */
