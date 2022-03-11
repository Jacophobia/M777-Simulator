#pragma once

#include "mass.h"
#include <cassert>

class TestMass
{
public:
	void run()
	{
		operatorTimesAcceleration_testZeroMass();
		operatorTimesAcceleration_testZeroAccel();
		operatorTimesAcceleration_testBothPos();
		operatorTimesAcceleration_testBothNeg();
		operatorTimesAcceleration_testAccNegMassPos();
		operatorTimesAcceleration_testAccPosMassNeg();
	}
private:
	void operatorTimesAcceleration_testZeroMass()
	{
		// setup
		Mass obj;
		obj.kgs = 0.0;
		Acceleration acc;
		acc.ddx = 1.0;
		acc.ddy = 1.0;
		// exercise
		Force result = obj * acc;
		// verify
		assert(result.N == 0.0);
	} // teardown
	void operatorTimesAcceleration_testZeroAccel()
	{
		// setup
		Mass obj;
		obj.kgs = 1.0;
		Acceleration acc;
		acc.ddx = 0.0;
		acc.ddy = 0.0;
		// exercise
		Force result = obj * acc;
		// verify
		assert(result.N == 0.0);
	} // teardown
	void operatorTimesAcceleration_testBothPos()
	{
		// setup
		Mass obj;
		obj.kgs = 1.0;
		Acceleration acc;
		acc.ddx = 1.0;
		acc.ddy = 1.0;
		// exercise
		Force result = obj * acc;
		// verify
		assert(result.N == 1.0);
	} // teardown
	void operatorTimesAcceleration_testBothNeg()
	{
		// setup
		Mass obj;
		obj.kgs = -1.0;
		Acceleration acc;
		acc.ddx = -1.0;
		acc.ddy = -1.0;
		// exercise
		Force result = obj * acc;
		// verify
		assert(result.N == -1.0);
	} // teardown
	void operatorTimesAcceleration_testAccNegMassPos()
	{
		// setup
		Mass obj;
		obj.kgs = 1.0;
		Acceleration acc;
		acc.ddx = -1.0;
		acc.ddy = -1.0;
		// exercise
		Force result = obj * acc;
		// verify
		assert(result.N == -1.0);
	} // teardown
	void operatorTimesAcceleration_testAccPosMassNeg()
	{
		// setup
		Mass obj;
		obj.kgs = -1.0;
		Acceleration acc;
		acc.ddx = 1.0;
		acc.ddy = 1.0;
		// exercise
		Force result = obj * acc;
		// verify
		assert(result.N == -1.0);
	} // teardown
};