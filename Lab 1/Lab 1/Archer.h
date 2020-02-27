#pragma once

#include "Arena.h"

class Archer : public Fighter {
public:

	Archer(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic);

	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();

private:
	int initialSpeed;
};
