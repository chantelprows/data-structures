#include "Pathfinder.h"
#include <array>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <fstream>




Pathfinder::Pathfinder() {
	srand(time(NULL));
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				curMaze[i][j][k] = 1;
			}
		}
	}
}

string Pathfinder::toString() const {
	stringstream ss;
	string s;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k < 5; ++k)
				{
					ss << curMaze[k][j][i];
					if (k < 4) {
						ss << " ";
					}
				}
				ss << endl;
			}
			if (i < 4) {
				ss << endl;
			}
		}
	s = ss.str();
	return s;
}

void Pathfinder::createRandomMaze() {
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				curMaze[i][j][k] = rand() % 2;
			}
		}
	}
	curMaze[0][0][0] = 1;
	curMaze[4][4][4] = 1;
	return;
}

bool Pathfinder::importMaze(string file_name) {
	ifstream ifs(file_name);
	string tmp;
	int oneCount = 0;

	while (!ifs.eof()) {
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k < 5; ++k)
				{
					ifs >> tmp;
					if (ifs.fail()) {
						return false;
					}
					else if (tmp != "0" && tmp != "1") {
						return false;
					}
					else {
						int value;
						value = atoi(tmp.c_str());
						maze[k][j][i] = value;
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				curMaze[i][j][k] = maze[i][j][k];
			}
		}
	}

	if (maze[0][0][0] != 1 || maze[4][4][4] != 1) {
		return false;
	}
	ifs.close();
	return true;
}

vector<string> Pathfinder::solveMaze() {
	string tmp;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				tmpMaze[i][j][k] = curMaze[i][j][k];
			}
		}
	}

	myvector.clear();
	findPath(tmpMaze, 0, 0, 0);
	return myvector;
}

bool Pathfinder::findPath(int maze[5][5][5], int x, int y, int z) {
	myvector.push_back("(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")");
	if (x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4) {
		myvector.pop_back();
		return false;
	}
	else if (maze[x][y][z] != 1) {
		myvector.pop_back();
		return false;
	}
	else if (maze[x][y][z] == 2) {
		myvector.pop_back();
		return false;
	}
	else if (x == 4 && y == 4 && z == 4) {
		maze[x][y][z] = 2;
		return true;
	}
	else {
		maze[x][y][z] = 2;
		if (findPath(maze, x + 1, y, z) // right
			|| findPath(maze, x - 1, y, z) // left
			|| findPath(maze, x, y + 1, z) // up
			|| findPath(maze, x, y - 1, z) // down
			|| findPath(maze, x, y, z + 1) // in
			|| findPath(maze, x, y, z - 1)) // out
		{ 
			return true;
		}
		else {
			myvector.pop_back();
			return false;
		}
	}
}

