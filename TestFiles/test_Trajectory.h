#pragma once
#include "trajectory.h"
#include <cassert>

class TestTrajectory
{
public:
	void run()
	{
		getPosition_testNormal();
		getPosition_testDefault();
		incrementTime_testZeros();
		incrementTime_testZeroSeconds();
		addAcceleration_testNormal();
		addAcceleration_testAddNegative();
	}
private:
	void getPosition_testNormal()
	{
		// setup
		Trajectory trajectory;
		Position src(5.0, 5.0);
		trajectory.position = src;
		// exercise
		Position result = trajectory.getPosition();
		// verify
		assert(result.x == 5.0);
		assert(result.y == 5.0);
		// takedown
	}
	void getPosition_testDefault()
	{
		// setup
		Trajectory trajectory;
		Position src;
		trajectory.position = src;
		// exercise
		Position result = trajectory.getPosition();
		// verify
		assert(result.x == 0.0);
		assert(result.y == 0.0);
		// takedown
	}
	void incrementTime_testZeros()
	{
		// setup
		Trajectory trajectory;
		trajectory.velocity = Velocity(0.0);
		trajectory.acceleration = Acceleration(0.0);
		trajectory.position = Position(0.0, 0.0);
		trajectory.angle = 0.0;
		// exercise
		trajectory.incrementTime(1.0);
		// verify
		assert(trajectory.velocity.dx == 0.0);
		assert(trajectory.velocity.dy == 0.0);
		assert(trajectory.acceleration.ddx == 0.0);
		assert(trajectory.acceleration.ddy == 0.0);
		assert(trajectory.position.x == 0.0);
		assert(trajectory.position.y == 0.0);
		assert(trajectory.angle == 0.0);
		// takedown
	}
	void incrementTime_testZeroSeconds()
	{
		// setup
		Trajectory trajectory;
		trajectory.velocity = Velocity(1.0, 1.0);
		trajectory.acceleration = Acceleration(1.0, 1.0);
		trajectory.position = Position(1.0, 1.0);
		trajectory.angle = 1.0;
		// exercise
		trajectory.incrementTime(0.0);
		// verify
		assert(trajectory.velocity.dx == 1.0);
		assert(trajectory.velocity.dy == 1.0);
		assert(trajectory.acceleration.ddx == 1.0);
		assert(trajectory.acceleration.ddy == 1.0);
		assert(trajectory.position.x == 1.0);
		assert(trajectory.position.y == 1.0);
		assert(trajectory.angle == 0.0);
		// takedown
	}
	void addAcceleration_testNormal()
	{
		// setup
		Acceleration src(10.0, 20.0);
		Trajectory trajectory;
		trajectory.velocity = Velocity(0.0);
		trajectory.acceleration = Acceleration(0.0);
		trajectory.position = Position(0.0, 0.0);
		trajectory.angle = 0.0;
		// exercise
		trajectory.addAcceleration(src);
		// verify
		assert(trajectory.velocity.dx == 0.0);
		assert(trajectory.velocity.dy == 0.0);
		assert(trajectory.acceleration.ddx == 10.0);
		assert(trajectory.acceleration.ddy == 20.0);
		assert(trajectory.position.x == 0.0);
		assert(trajectory.position.y == 0.0);
		assert(trajectory.angle == 0.0);
		// takedown
	}
	void addAcceleration_testAddNegative()
	{
		// setup
		Acceleration src(-5.0, 0.0);
		Trajectory trajectory;
		trajectory.velocity = Velocity(0.0);
		trajectory.acceleration = Acceleration(0.0);
		trajectory.position = Position(0.0, 0.0);
		trajectory.angle = 0.0;
		// exercise
		trajectory.addAcceleration(src);
		// verify
		assert(trajectory.velocity.dx == 0.0);
		assert(trajectory.velocity.dy == 0.0);
		assert(trajectory.acceleration.ddx == -5.0);
		assert(trajectory.acceleration.ddy == 0.0);
		assert(trajectory.position.x == 0.0);
		assert(trajectory.position.y == 0.0);
		assert(trajectory.angle == 0.0);
		// takedown
	}
};