
/*
QuadEncoder.cpp
Copyright (c) 2014 Aaditya Dengle.
*/
#include "Arduino.h"
#include "QuadEncoder.h"
#include "digitalWriteFast/digitalWriteFast.h"//<digitalWriteFast/digitalWriteFast.h>
#include <stdint.h>
int _State;
int _lState;
uint8_t _pinA;
uint8_t _pinB;
uint8_t _intA;
uint8_t _intB;
long ReadCount();
void SetCount(long NewCount);
void Reset();
long Count = 0;

void CheckState();
QuadEncoder::QuadEncoder(uint8_t pinA, uint8_t pinB)
{
	_State=0;
	_lState=0;
	pinMode(pinA, INPUT_PULLUP);
	_pinA = pinA;
	pinMode(pinB, INPUT_PULLUP);
	_pinB = pinB;
	
	switch (pinA) {
		case 2:{
			_intA = 0;
		}
		case 3:{
			_intA = 1;
		}
		case 21:{
			_intA = 2;
		}
		case 20:{
			_intA = 3;
		}
		case 19:{
			_intA = 4;
		}
		case 18:{
			_intA = 5;
		}
	}
	switch (pinB) {
		case 2:{
			_intB = 0;
		}
		case 3:{
			_intB = 1;
		}
		case 21:{
			_intB = 2;
		}
		case 20:{
			_intB = 3;
		}
		case 19:{
			_intB = 4;
		}
		case 18:{
			_intB = 5;
		}
	}
	attachInterrupt (_intA,CheckState,CHANGE);
}

void CheckState()
{
	_lState = _State;
	_State = _State << digitalReadFast2(_pinA);
	_State = _State << digitalReadFast2(_pinB);
	
	switch (_State){
		case 0:{
			if (_lState==8){
				Count++;
			}
			if (_lState==1){
				Count--;
			}
		}
		case 1:{
			if (_lState==0){
				Count++;
			}
			if (_lState==7){
				Count--;
			}
		}
		case 7:{
			if (_lState==1){
				Count++;
			}
			if (_lState==14){
				Count--;
			}
		}
		case 14:{
			if (_lState==7){
				Count++;
			}
			if (_lState==8){
				Count--;
			}
			
		}
		case 8:{
			if (_lState==14){
				Count++;
			}
			if (_lState==0){
				Count--;
			}
			
		}
		
	}
}

void Reset()
{
	Count=0;
}

void SetCount(long NewCount)
{
	Count=NewCount;
}

long ReadCount()
{
	return Count;
}

