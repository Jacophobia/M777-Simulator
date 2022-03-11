#pragma once
#include "force.h"
#include "mass.h"
#include "acceleration.h"
#include <cassert>

class TestForce
{
public:
	void run()
	{
		operatorDivMass_testDivByZero();
		operatorDivMass_testZeroForcePosMass();
		operatorDivMass_testZeroForceNegMass();
		operatorDivMass_testNegForceZeroMass();
		operatorDivMass_testNegForcePosMass();
		operatorDivMass_testPosForceNegMass();
		operatorDivMass_testNegForceNegMass();
		operatorDivMass_testPosForcePosMass();
		operatorDivMass_testBothZero();

		operatorDivAcceleration_testDivByZero();
		operatorDivAcceleration_testDivByZero();
		operatorDivAcceleration_testZeroForcePosAcc();
		operatorDivAcceleration_testZeroForceNegAcc();
		operatorDivAcceleration_testPosForceZeroAcc();
		operatorDivAcceleration_testNegForceZeroAcc();
		operatorDivAcceleration_testNegForcePosAcc();
		operatorDivAcceleration_testPosForceNegAcc();
		operatorDivAcceleration_testNegForceNegAcc();
		operatorDivAcceleration_testPosForcePosAcc();
		operatorDivAcceleration_testBothZero();
	}
private:
	void operatorDivMass_testDivByZero()
	{
		// setup
		Force frc;
		frc.N = 1.0;
		Mass mass;
		mass.kgs = 0.0;
		Acceleration result(0.0);
		// exercise
		try
		{
			result.totalAccl = frc / mass;
		}
		// verify
		catch (...)
		{
			assert(result.totalAccl == 0.0);
		}
	}

	void operatorDivMass_testZeroForcePosMass()
	{
		// setup
		Force frc;
		frc.N = 0.0;
		Mass mass;
		mass.kgs = 1.0;
		Acceleration result(0.0);
		result.totalAccl = 0.0;
		// exercise
		result.totalAccl = frc / mass;
		// verify
		assert(result.totalAccl == 0.0);
	}	//  teardown

	void operatorDivMass_testZeroForceNegMass()
	{
		// setup
		Force frc;
		frc.N = 0.0;
		Mass mass;
		mass.kgs = -1.0;
		Acceleration result(0.0);
		result.totalAccl = 0.0;
		// exercise
		result.totalAccl = frc / mass;
		// verify
		assert(result.totalAccl == 0.0);
	}	//  teardown

	void operatorDivMass_testNegForceZeroMass()
	{
		// setup
		Force frc;
		frc.N = -1.0;
		Mass mass;
		mass.kgs = 0.0;
		Acceleration result(0.0);
		// exercise
		try
		{
			result.totalAccl = frc / mass;
		}
		// verify
		catch (...)
		{
			assert(result.totalAccl == 0.0);
		}
	}	//  teardown

	void operatorDivMass_testNegForcePosMass()
	{
		// setup
		Force frc;
		frc.N = -1.0;
		Mass mass;
		mass.kgs = 1.0;
		Acceleration result(0.0);
		result.totalAccl = 0.0;
		// exercise
		result.totalAccl = frc / mass;
		// verify
		assert(result.totalAccl == -1.0);
	}	//  teardown

	void operatorDivMass_testPosForceNegMass()
	{
		// setup
		Force frc;
		frc.N = 1.0;
		Mass mass;
		mass.kgs = -1.0;
		Acceleration result(0.0);
		result.totalAccl = 0.0;
		// exercise
		result.totalAccl = frc / mass;
		// verify
		assert(result.totalAccl == -1.0);
	}	//  teardown

	void operatorDivMass_testNegForceNegMass()
	{
		// setup
		Force frc;
		frc.N = -1.0;
		Mass mass;
		mass.kgs = -1.0;
		Acceleration result(0.0);
		result.totalAccl = 0.0;
		// exercise
		result.totalAccl = frc / mass;
		// verify
		assert(result.totalAccl == 1.0);
	}	//  teardown

	void operatorDivMass_testPosForcePosMass()
	{
		// setup
		Force frc;
		frc.N = 1.0;
		Mass mass;
		mass.kgs = 1.0;
		Acceleration result(0.0);
		result.totalAccl = 0.0;
		// exercise
		result.totalAccl = frc / mass;
		// verify
		assert(result.totalAccl == 1.0);
	}	//  teardown

	void operatorDivMass_testBothZero()
	{
		// setup
		Force frc;
		frc.N = 0.0;
		Mass mass;
		mass.kgs = 0.0;
		Acceleration result(0.0);
		// exercise
		try
		{
			result.totalAccl = frc / mass;
		}
		// verify
		catch (...)
		{
			assert(result.totalAccl == 0.0);
		}
	}	//  teardown




	// to do ^



	void operatorDivAcceleration_testDivByZero()
	{
		//setup
		Force frc;
		Acceleration accr(0.0);
		frc.N = 0.0;
		Mass result;
		//exercise
		try
		{
			result.kgs = frc / accr;
		}
		// verify
		catch (...)
		{
			assert(result.kgs == 0.0);
		}
	}	//teardown


	void operatorDivAcceleration_testZeroForcePosAcc()
	{
		//setup
		Force frc;
		Acceleration accr(1.0);
		frc.N = 0.0;
		Mass result;
		//exercise
			result.kgs = frc / accr;
		// verify
			assert(result.kgs == 0.0);
	}	//teardown

	void operatorDivAcceleration_testZeroForceNegAcc()
	{
		//setup
		Force frc;
		Acceleration accr(-1.0);
		frc.N = 0.0;
		Mass result;
		//exercise
		result.kgs = frc / accr;
		// verify
		assert(result.kgs == 0.0);
	}	//teardown

	void operatorDivAcceleration_testPosForceZeroAcc()
	{
		//setup
		Force frc;
		Acceleration accr(0.0);
		frc.N = 1.0;
		Mass result;
		//exercise
		try
		{
			result.kgs = frc / accr;
		}
		// verify
		catch (...)
		{
			assert(result.kgs == 0.0);
		}
	}	//teardown

	void operatorDivAcceleration_testNegForceZeroAcc()
	{
		//setup
		Force frc;
		Acceleration accr(0.0);
		frc.N = -1.0;
		Mass result;
		//exercise
		try
		{
			result.kgs = frc / accr;
		}
		// verify
		catch (...)
		{
			assert(result.kgs == 0.0);
		}
	}	//teardown

	void operatorDivAcceleration_testNegForcePosAcc()
	{
		//setup
		Force frc;
		Acceleration accr(1.0);
		frc.N = -1.0;
		Mass result;
		//exercise
		result.kgs = frc / accr;
		//verify
		assert(result.kgs == -1.0);
	}	//teardown

	void operatorDivAcceleration_testPosForceNegAcc()
	{
		//setup
		Force frc;
		Acceleration accr(-1.0);
		frc.N = 1.0;
		Mass result;
		//exercise
		result.kgs = frc / accr;
		//verify
		assert(result.kgs == -1.0);
	}	//teardown

	void operatorDivAcceleration_testNegForceNegAcc()
	{
		//setup
		Force frc;
		Acceleration accr(-1.0);
		frc.N = -1.0;
		Mass result;
		//exercise
		result.kgs = frc / accr;
		//verify
		assert(result.kgs == 1.0);
	}	//teardown

	void operatorDivAcceleration_testPosForcePosAcc()
	{
		//setup
		Force frc;
		Acceleration accr(1.0);
		frc.N = 1.0;
		Mass result;
		//exercise
		result.kgs = frc / accr;
		//verify
		assert(result.kgs == 1.0);
	}	//teardown

	void operatorDivAcceleration_testBothZero()
	{
		//setup
		Force frc;
		Acceleration accr(0.0);
		frc.N = 0.0;
		Mass result;
		//exercise
		try
		{
			result.kgs = frc / accr;
		}
		// verify
		catch (...)
		{
			assert(result.kgs == 0.0);
		}
	}	//teardown

};