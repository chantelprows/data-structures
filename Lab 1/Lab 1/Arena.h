#pragma once

#include "ArenaInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <vector>

class Arena : public ArenaInterface
{
public:
	virtual bool addFighter(std::string info);

	virtual bool removeFighter(std::string name);

	virtual FighterInterface* getFighter(std::string name);

	virtual int getSize() const;

protected:
	std::vector<FighterInterface*> fighters;
};
