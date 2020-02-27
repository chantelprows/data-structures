#include "Fighter.h"

Fighter::Fighter(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic) {
	name = inputName;
	maxhp = inputMaxhp;
	curhp = inputMaxhp;
	strength = inputStrength;
	speed = inputSpeed;
	magic = inputMagic;
}

std::string Fighter::getName() const {
	return name;
}

int Fighter::getMaximumHP() const {
	return maxhp;
}

int Fighter::getCurrentHP() const {
	return curhp;
}

int Fighter::getStrength() const {
	return strength;
}

int Fighter::getSpeed() const {
	return speed;
}

int Fighter::getMagic() const {
	return magic;
}

int Fighter::getDamage() {
	return 0;
}

void Fighter::takeDamage(int damage) {
	return;
}

void Fighter::reset() {
	return;
}

void Fighter::regenerate() {
	return;
}

bool Fighter::useAbility() {
	return false;
}