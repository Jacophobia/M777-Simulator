#pragma once

#include "velocity.h"
#include <cassert>

class TestVelocity
{
public:
	void run()
	{
		operatorPlusEqualsAcceleration_testAddZero();
		operatorTimesVelocity_testNormal();
		operatorPlusVelocity_testAddNormaltoZero();
		operatorTimesDouble_testDivideBy2();
		operatorTimesDouble_testMultiplyBy2();
	}
private:
	void operatorPlusEqualsAcceleration_testAddZero()
	{
		// setup
		Velocity velocity;
		velocity.dx = 0.0;
		velocity.dy = 0.0;
		Acceleration src;
		src.ddx = 0.0;
		src.ddy = 0.0;
		Seconds seconds;
		seconds.seconds = 1.0;
		// exercise
		velocity.update(src, seconds);
		// verify
		assert(velocity.dx == 0.0);
		assert(velocity.dy == 0.0);
		// takedown
	}
	void operatorTimesVelocity_testNormal()
	{
		// setup
		Velocity v1;
		v1.dx = 1.0;
		v1.dy = 1.0;
		Velocity v2;
		v2.dx = 4.0;
		v2.dy = 3.0;
		// exercise
		double result = v1 * v2;
		// verify
		assert(result == 5.0);
		assert(v1.dx == 1.0);
		assert(v1.dy == 1.0);
		assert(v2.dx == 4.0);
		assert(v2.dy == 3.0);
		// takedown
	}
	void operatorPlusVelocity_testAddNormaltoZero()
	{
		// setup
		Velocity v1;
		v1.dx = 0.0;
		v1.dy = 0.0;
		Velocity v2;
		v2.dx = 5.0;
		v2.dy = 5.0;
		// exercise
		Velocity result = v1 + v2;
		// verify
		assert(result.dx == 5.0);
		assert(result.dy == 5.0);
		assert(v1.dx == 0.0);
		assert(v1.dy == 0.0);
		assert(v2.dx == 5.0);
		assert(v2.dy == 5.0);
		// takedown
	}
	void operatorPlusVelocity_testAddNormaltoNormal()
	{
		// setup
		Velocity v1;
		v1.dx = 4.0;
		v1.dy = 3.0;
		Velocity v2;
		v2.dx = 5.0;
		v2.dy = 5.0;
		// exercise
		Velocity result = v1 + v2;
		// verify
		assert(result.dx == 9.0);
		assert(result.dy == 8.0);
		assert(v1.dx == 4.0);
		assert(v1.dy == 3.0);
		assert(v2.dx == 5.0);
		assert(v2.dy == 5.0);
		// takedown
	}
	void operatorTimesDouble_testDivideBy2()
	{
		// setup
		Velocity v;
		v.dx = 5.0;
		v.dy = 5.0;
		double d = 0.5;
		// exercise
		Velocity result = v * d;
		// verify
		assert(result.dx == 2.5);
		assert(result.dy == 2.5);
		assert(v.dx == 5.0);
		assert(v.dy == 5.0);
		// takedown
	}
	void operatorTimesDouble_testMultiplyBy2()
	{
		// setup
		Velocity v;
		v.dx = 5.0;
		v.dy = 5.0;
		double d = 2.0;
		// exercise
		Velocity result = v * d;
		// verify
		assert(result.dx == 10.0);
		assert(result.dy == 10.0);
		assert(v.dx == 5.0);
		assert(v.dy == 5.0);
		// takedown
	}
};