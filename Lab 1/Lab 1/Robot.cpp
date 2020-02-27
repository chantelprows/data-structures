#include "Robot.h"

Robot::Robot(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic)
	:Fighter(inputName, inputMaxhp, inputCurhp, inputStrength, inputSpeed, inputMagic) {
	
	maxEnergy = 2 * magic;
	curEnergy = 2 * magic;
	bonusDamage = 0;
}

int Robot::getDamage() {
	int abilityStrength = strength + bonusDamage;
	bonusDamage = 0;
	return abilityStrength;
}

void Robot::takeDamage(int damage) {
	if ((damage - (speed / 4)) < 1) {
		curhp = curhp - 1;
	}

	else {
		curhp = curhp - (damage - (speed / 4));
	}
}

void Robot::reset() {
	curhp = maxhp;
	curEnergy = maxEnergy;
	bonusDamage = 0;
}

void Robot::regenerate() {
	if ((strength / 6) < 1) {
		if (curhp + 1 < maxhp) {
			curhp = curhp + 1;
		}
		else {
			curhp = maxhp;
		}
	}
	else {
		if (curhp + (strength / 6) < maxhp) {
			curhp = curhp + (strength / 6);
		}
		else {
			curhp = maxhp;
		}
	}
	return;
}

bool Robot::useAbility() {
	if (curEnergy >= ROBOT_ABILITY_COST) {
		bonusDamage = bonusDamage + (double)strength  * pow(((double)curEnergy / maxEnergy), 4);
		curEnergy = curEnergy - ROBOT_ABILITY_COST;
		return true;
	}
	else {
		return false;
	}
}
