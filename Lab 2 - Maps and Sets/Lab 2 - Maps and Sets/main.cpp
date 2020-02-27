#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <time.h>
#include <cctype>

int main(int argc, char* argv[]) {

	std::ifstream ifs;
	std::ofstream ofs;
	std::ofstream ofs1;
	std::ofstream ofs2;
	std::string inputfile = argv[1];
	std::string outputfile = argv[2];
	std::set<std::string> myset;
	std::vector <std::string> myvector;
	std::map <std::string, std::string> mymap;
	std::map <std::string, std::vector<std::string>> mymap2;
	std::map <std::list<std::string>, std::vector<std::string >> mymap3;

	ifs.open(argv[1]);
	ofs.open(outputfile + "_set.txt");


	std::string str;
	while (ifs >> str)
	{
		int i = 0;
		char c;
		std::string newStr;
		while (str[i])
		{
			c = str[i];
			if (isalpha(c)) {
				newStr.append(1, tolower(c));
			}
			else if (newStr.length() != 0) {
				myset.insert(newStr);
				newStr.clear();
			}
			i++;
		}
		
		if (newStr.length() != 0) {
			myset.insert(newStr);
		}
	}

		ifs.close();
		ifs.clear();
		ifs.seekg(0, ifs.beg);

		ifs.open(argv[1]);
		ofs1.open(outputfile + "_vector.txt");

		//if (ifs.is_open()) {
		//	std::cout << "file opened";
			//}

	while (ifs >> str)
	{			
		int i = 0;
		char a;			
		std::string vecStr;
		while (str[i])
		{
			a = str[i];
			if (isalpha(a)) {
				vecStr.append(1, tolower(a));
			}
			else if (vecStr.length() != 0) {
				myvector.push_back(vecStr);
				vecStr.clear();
			}
			i++;
		}

		if (vecStr.length() != 0) {
			myvector.push_back(vecStr);
		}
	}

	ifs.clear();
	ifs.seekg(0, ifs.beg);
	

	for (std::string word : myset) {
		ofs << word << std::endl;
	}

	ofs.close();

	for (std::string word : myvector) {
		ofs1 << word << std::endl;
	}
	
	ofs1.close();
	ofs2.open(outputfile + "_1_1.txt");
	
	std::string last = "";
	std::vector<std::string>::iterator it;
	for (it = myvector.begin(); it != myvector.end(); it++) {
		mymap[last] = *it;
		last = *it;
	}

	for (std::pair<const std::string, std::string>& element : mymap) {
		ofs2 << element.first << ", " << element.second << std::endl;
	}

	ofs2.close();

	std::string state = "";
	for (int i = 0; i < 100; i++) {
		std::cout << mymap[state] << " ";
		state = mymap[state];
	}

	std::cout << std::endl;

	std::string last2 = "";
	std::vector<std::string>::iterator it2;
	for (it2 = myvector.begin(); it2 != myvector.end(); it2++) {
		mymap2[last2].push_back(*it2);
		last2 = *it2;
	}

	srand(time(NULL));
	std::string state2 = "";
	for (int i = 0; i < 100; i++) {
		if (mymap2[state2].size() == 0) {
		state2 = "";
		}
		else {
			int ind = rand() % mymap2[state2].size();
			std::cout << mymap2[state2][ind] << " ";
			state2 = mymap2[state2][ind];
		}
	}

	std::cout << std::endl;

	std::list<std::string> last3;
	int M = 2;
	for (int i = 0; i < M; i++) {
		last3.push_back("");
	}
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); it++) {
		mymap3[last3].push_back(*it);
		last3.push_back(*it);
		last3.pop_front();
	}

	std::list<std::string> state3;
	for (int i = 0; i < M; i++) {
		state3.push_back("");
	}
	for (int i = 0; i < 100; i++) {
		if (mymap3[state3].size() == 0) {
			state3.clear();
			for (int i = 0; i < M; i++) {
				state3.push_back("");
			}
		}
		else {
			int ind = rand() % mymap3[state3].size();
			std::cout << mymap3[state3][ind] << " ";
			state3.push_back(mymap3[state3][ind]);
			state3.pop_front();
		}
	}

	std::cout << std::endl;

	ifs.close();
	
	system("pause");

}