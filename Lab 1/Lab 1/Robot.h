#pragma once

#include "Arena.h"
#include <cmath>

class Robot : public Fighter {
public:

	Robot(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic);

	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();

private:
	int maxEnergy;
	int curEnergy;
	int bonusDamage;
};