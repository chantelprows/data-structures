#pragma once
#include "PathfinderInterface.h"

class Pathfinder : public PathfinderInterface {

public:

	Pathfinder();
	~Pathfinder() {}
	
	string toString() const;

	void createRandomMaze();

	bool importMaze(string file_name);

	vector<string> solveMaze();

	bool findPath(int maze[5][5][5], int x, int y, int z);

private:

	vector<string> myvector;
	int maze[5][5][5];
	int tmpMaze[5][5][5];
	int curMaze[5][5][5];
};

