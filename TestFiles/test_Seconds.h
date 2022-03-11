#pragma once

#include "seconds.h"
#include <cassert>

class TestSeconds
{
public:
	void run()
	{
		operatorTimesAcceleration_testZeroSecs();
		operatorTimesAcceleration_testZeroAccel();
		operatorTimesAcceleration_testBothPos();
		operatorTimesAcceleration_testBothNeg();
		operatorTimesAcceleration_testAccNegSecsPos();
		operatorTimesAcceleration_testAccPosSecsNeg();
	}
private:
	// Tests for when seconds equals zero and acceleration is 
	// multiplied by that
	// Expected result: 
	//    Velocity equaling acceleration's value
	void operatorTimesAcceleration_testZeroSecs()
	{
		// setup
		Seconds obj;
		obj.seconds = 0.0;
		Acceleration acc;
		acc.ddx = 1.0;
		acc.ddy = 1.0;
		// exercise
		Velocity result = obj * acc;
		// verify
		assert(result.dx == 0.0);
		assert(result.dy == 0.0);
	} // teardown
	void operatorTimesAcceleration_testZeroAccel()
	{
		// setup
		Seconds obj;
		obj.seconds = 1.0;
		Acceleration acc;
		acc.ddx = 0.0;
		acc.ddy = 0.0;
		// exercise
		Velocity result = obj * acc;
		// verify
		assert(result.dx == 0.0);
		assert(result.dy == 0.0);
	} // teardown
	void operatorTimesAcceleration_testBothPos()
	{
		// setup
		Seconds obj;
		obj.seconds = 1.0;
		Acceleration acc;
		acc.ddx = 1.0;
		acc.ddy = 1.0;
		// exercise
		Velocity result = obj * acc;
		// verify
		assert(result.dx == 1.0);
		assert(result.dy == 1.0);
	} // teardown
	void operatorTimesAcceleration_testBothNeg()
	{
		// setup
		Seconds obj;
		obj.seconds = -1.0;
		Acceleration acc;
		acc.ddx = -1.0;
		acc.ddy = -1.0;
		// exercise
		Velocity result = obj * acc;
		// verify
		assert(result.dx == 1.0);
		assert(result.dy == 1.0);
	} // teardown
	void operatorTimesAcceleration_testAccNegSecsPos()
	{
		// setup
		Seconds obj;
		obj.seconds = 1.0;
		Acceleration acc;
		acc.ddx = -1.0;
		acc.ddy = -1.0;
		// exercise
		Velocity result = obj * acc;
		// verify
		assert(result.dx == -1.0);
		assert(result.dy == -1.0);
	} // teardown
	void operatorTimesAcceleration_testAccPosSecsNeg()
	{
		// setup
		Seconds obj;
		obj.seconds = -1.0;
		Acceleration acc;
		acc.ddx = 1.0;
		acc.ddy = 1.0;
		// exercise
		Velocity result = obj * acc;
		// verify
		assert(result.dx == -1.0);
		assert(result.dy == -1.0);
	} // teardown
};