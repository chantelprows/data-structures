#include "Archer.h"

Archer::Archer(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic)
	:Fighter(inputName, inputMaxhp, inputCurhp, inputStrength, inputSpeed, inputMagic) {

	initialSpeed = speed;

}

int Archer::getDamage() {
	return speed;
}

void Archer::takeDamage(int damage) {
	if ((damage - (speed / 4)) < 1) {
		curhp = curhp - 1;
	}

	else {
		curhp = curhp - (damage - (speed / 4));
	}
}

void Archer::reset() {
	curhp = maxhp;
	speed = initialSpeed;
}

void Archer::regenerate() {

	if ((strength/6) < 1) {
		if (curhp + 1 < maxhp) {
			curhp = curhp + 1;
		}
		else {
			curhp = maxhp;
		}
	}
	else {
		if (curhp + (strength/6) < maxhp) {
			curhp = curhp + (strength/6);
		}
		else {
			curhp = maxhp;
		}
	}
	return;
}

bool Archer::useAbility() {
	speed = speed + 1;
	return true;
}

