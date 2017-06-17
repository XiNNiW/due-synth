/*
 * IEnvelopeGenerator.h
 *
 *  Created on: Jun 7, 2017
 *      Author: davidminnix
 */

#ifndef INCLUDE_SYNTHESIS_IENVELOPEGENERATOR_H_
#define INCLUDE_SYNTHESIS_IENVELOPEGENERATOR_H_
namespace sunthesis{
class IEnvelopeGenerator{
public:
	IEnvelopeGenerator(){};
	virtual ~IEnvelopeGenerator(){};
	virtual float advance()=0;
	virtual void start()=0;
	virtual void stop()=0;
};
}

#endif /* INCLUDE_SYNTHESIS_IENVELOPEGENERATOR_H_ */
