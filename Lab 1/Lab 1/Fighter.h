#pragma once

#include "FighterInterface.h"

class Fighter : public FighterInterface
{
public:

	Fighter(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic);

	virtual std::string getName() const;

	virtual int getMaximumHP() const;

	virtual int getCurrentHP() const;

	virtual int getStrength() const;

	virtual int getSpeed() const;

	virtual int getMagic() const;

	virtual int getDamage();

	virtual void takeDamage(int damage);

	virtual void reset();

	virtual void regenerate();

	virtual bool useAbility();

protected:
	std::string name;
	int maxhp;
	int curhp;
	int strength;
	int speed;
	int magic;
};

