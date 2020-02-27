#include "Arena.h"
#include <vector>
#include <sstream>


bool Arena::addFighter(std::string info) {

	std::stringstream ss(info);

	std::string name, type;
	int maxhp = 0, curhp = 0, strength = 0, speed = 0, magic = 0;

	ss >> name >> type >> maxhp >> strength >> speed >> magic;

	if (!ss) {
		return false;
	}
	int overflow;
	if (!ss.eof()) {
		return false;
	}

	if (maxhp <= 0) {
		return false;
	}

	if (strength <= 0) {
		return false;
	}

	if (speed <= 0) {
		return false;
	}

	if (magic <= 0) {
		return false;
	}

	for (int i = 0; i < fighters.size(); i++) {
		std::string newName = fighters.at(i)->getName();
		if (newName == name) {
			return false;
		}
	}

	if (ss.fail()) {
		return false;
	}

	if (type == "A") {
		fighters.push_back(new Archer(name, maxhp, curhp, strength, speed, magic));
		return true;
	}

	if (type == "C") {
		fighters.push_back(new Cleric(name, maxhp, curhp, strength, speed, magic));
		return true;
	}

	if (type == "R") {
		fighters.push_back(new Robot(name, maxhp, curhp, strength, speed, magic));
		return true;
	}

	if (type != "A" || type != "C" || type != "R") {
		return false;
	}

	return false;

}

bool Arena::removeFighter(std::string name) {

	for (int i = 0; i < fighters.size(); i++) {
		if (name == fighters.at(i)->getName()) {
			fighters.erase(fighters.begin() + i);
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(std::string name) {

	for (int i = 0; i < fighters.size(); i++) {
		if (name == fighters.at(i)->getName()) {
			return fighters.at(i);
		}
	}
	return NULL;
}

int Arena::getSize() const {
	return fighters.size();
}