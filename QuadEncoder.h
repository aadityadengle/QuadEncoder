/*
QuadEncoder.h - Library for reading Quadrature Encoders on simple ISR
version 0.0.1 
*/
#ifndef QuadEncoder_h
#define QuadEncoder_h

#include <stdlib.h>
#include <stdint.h>


#include "Arduino.h"
class QuadEncoder
{
	public:
	QuadEncoder(uint8_t pinA, uint8_t pinB);
	long ReadCount();
	void SetCount(long NewCount);
	void Reset();
	long Count;

	


	};
#endif