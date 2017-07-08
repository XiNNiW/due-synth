/*
 * IAudioGenerator.h
 *
 *  Created on: Feb 6, 2017
 *      Author: davidminnix
 */

#ifndef INCLUDE_IAUDIOGENERATOR_H_
#define INCLUDE_IAUDIOGENERATOR_H_
#include <CommonTypes.h>
namespace sunthesis{
class IAudioGenerator{

public:
	IAudioGenerator(){}
	virtual sample nextSample()=0;
	virtual ~IAudioGenerator(){};
};
}
#endif /* INCLUDE_IAUDIOGENERATOR_H_ */
