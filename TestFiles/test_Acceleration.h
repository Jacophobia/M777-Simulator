#pragma once

class TestAcceleration
{
public:
	void run()
	{
		operatorTimesMass_testZeroMass();
		operatorTimesMass_testZeroAccel();
		operatorTimesMass_testBothPos();
		operatorTimesMass_testBothNeg();
		operatorTimesMass_testAccNegMassPos();
		operatorTimesMass_testAccPosMassNeg();


		operatorTimesSeconds_testZeroSecs();
		operatorTimesSeconds_testZeroAccel();
		operatorTimesSeconds_testBothPos();
		operatorTimesSeconds_testBothNeg();
		operatorTimesSeconds_testAccNegSecsPos();
		operatorTimesSeconds_testAccPosSecsNeg();


		operatorTimesDouble_testZeroDouble();
		operatorTimesDouble_testZeroAccel();
		operatorTimesDouble_testBothPos();
		operatorTimesDouble_testBothNeg();
		operatorTimesDouble_testAccNegDoublePos();
		operatorTimesDouble_testAccPosDoubleNeg();


		operatorPlusEqualsAcceleration_testAddZeroToZero();
		operatorPlusEqualsAcceleration_testAddZeroToNeg();
		operatorPlusEqualsAcceleration_testAddZeroToPos();
		operatorPlusEqualsAcceleration_testAddPosToZero();
		operatorPlusEqualsAcceleration_testAddPosToNeg();
		operatorPlusEqualsAcceleration_testAddPosToPos();
		operatorPlusEqualsAcceleration_testAddNegToZero();
		operatorPlusEqualsAcceleration_testAddNegToNeg();
		operatorPlusEqualsAcceleration_testAddNegToPos();


		operatorMinusAcceleration_testSubtZeroFromZero();
		operatorMinusAcceleration_testSubtZeroFromNeg();
		operatorMinusAcceleration_testSubtZeroFromPos();
		operatorMinusAcceleration_testSubtNegFromZero();
		operatorMinusAcceleration_testSubtNegFromNeg();
		operatorMinusAcceleration_testSubtNegFromPos();
		operatorMinusAcceleration_testSubtPosFromZero();
		operatorMinusAcceleration_testSubtPosFromNeg();
		operatorMinusAcceleration_testSubtPosFromPos();
	}
private:
	void operatorTimesMass_testZeroMass();
	void operatorTimesMass_testZeroAccel();
	void operatorTimesMass_testBothPos();
	void operatorTimesMass_testBothNeg();
	void operatorTimesMass_testAccNegMassPos();
	void operatorTimesMass_testAccPosMassNeg();


	void operatorTimesSeconds_testZeroSecs();
	void operatorTimesSeconds_testZeroAccel();
	void operatorTimesSeconds_testBothPos();
	void operatorTimesSeconds_testBothNeg();
	void operatorTimesSeconds_testAccNegSecsPos();
	void operatorTimesSeconds_testAccPosSecsNeg();


	void operatorTimesDouble_testZeroDouble();
	void operatorTimesDouble_testZeroAccel();
	void operatorTimesDouble_testBothPos();
	void operatorTimesDouble_testBothNeg();
	void operatorTimesDouble_testAccNegDoublePos();
	void operatorTimesDouble_testAccPosDoubleNeg();


	void operatorPlusEqualsAcceleration_testAddZeroToZero();
	void operatorPlusEqualsAcceleration_testAddZeroToNeg();
	void operatorPlusEqualsAcceleration_testAddZeroToPos();
	void operatorPlusEqualsAcceleration_testAddPosToZero();
	void operatorPlusEqualsAcceleration_testAddPosToNeg();
	void operatorPlusEqualsAcceleration_testAddPosToPos();
	void operatorPlusEqualsAcceleration_testAddNegToZero();
	void operatorPlusEqualsAcceleration_testAddNegToNeg();
	void operatorPlusEqualsAcceleration_testAddNegToPos();


	void operatorMinusAcceleration_testSubtZeroFromZero();
	void operatorMinusAcceleration_testSubtZeroFromNeg();
	void operatorMinusAcceleration_testSubtZeroFromPos();
	void operatorMinusAcceleration_testSubtNegFromZero();
	void operatorMinusAcceleration_testSubtNegFromNeg();
	void operatorMinusAcceleration_testSubtNegFromPos();
	void operatorMinusAcceleration_testSubtPosFromZero();
	void operatorMinusAcceleration_testSubtPosFromNeg();
	void operatorMinusAcceleration_testSubtPosFromPos();


};