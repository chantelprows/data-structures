#include "Cleric.h"

Cleric::Cleric(std::string inputName, int inputMaxhp, int inputCurhp, int inputStrength, int inputSpeed, int inputMagic)
	:Fighter(inputName, inputMaxhp, inputCurhp, inputStrength, inputSpeed, inputMagic) {
	maxMana = 5 * magic;
	curMana = 5 * magic;
}

int Cleric::getDamage() {
	return magic;
}

void Cleric::takeDamage(int damage) {
	if ((damage - (speed / 4)) < 1) {
		curhp = curhp - 1;
	}

	else {
		curhp = curhp - (damage - (speed / 4));
	}
}

void Cleric::reset() {
	curhp = maxhp;
	curMana = maxMana;

}

void Cleric::regenerate() {
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

	if ((magic / 5) < 1) {
		if (curMana + 1 < maxMana) {
			curMana = curMana + 1;
		}
		else {
			curMana = maxMana;
		}
	}

	else {
		if (curMana + (magic / 5) < maxhp) {
			curMana = curMana + (magic / 5);
		}
		else {
			curMana = maxMana;
		}
	}
	return;
}

bool Cleric::useAbility() {

	if (curMana >= CLERIC_ABILITY_COST) {
		if (curhp + (magic / 3) < maxhp) {
			curhp = curhp + (magic / 3);
		}
		else if (curhp + 1 < maxhp) {
			curhp = curhp + 1;
		}
		else {
			curhp = maxhp;
		}
		curMana = curMana - CLERIC_ABILITY_COST;

		return true;
	}
	else {
		return false;
	}
}