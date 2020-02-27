#include "ExpressionManager.h"
#include <stack>
#include <sstream>
#include <algorithm>

bool ExpressionManager::isBalanced(string expression) {
	stack <string> mystack;
	stringstream ss(expression);
	string tmp, tmp2;

	while (!ss.eof()) {
		ss >> tmp;
		if (tmp == "(" || tmp == "{" || tmp == "[") {
			mystack.push(tmp);
		}
		else {
			if (mystack.empty()) {
				return false;
			}
			tmp2 = mystack.top();
			mystack.pop();
			if (tmp == ")") {
				if (tmp2 != "(") {
					return false;
				}
			}
			else if (tmp == "}") {
				if (tmp2 != "{") {
					return false;
				}
			}
			else if (tmp == "]") {
				if (tmp2 != "[") {
					return false;
				}
			}
		}
	}
	if (mystack.empty()) {
		return true;
	}
	return false;
}

string ExpressionManager::postfixToInfix(string postfixExpression) {
	stack <string> mystack;
	stringstream ss(postfixExpression);
	string tmp, tmp2, tmp3, tmp4;

	while (!ss.eof()) {
		ss >> tmp;
		if (!(all_of(tmp.begin(), tmp.end(), ::isdigit))
			&& tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/" && tmp != "%"
			&& tmp != "{" && tmp != "}" && tmp != "(" && tmp != ")" && tmp != "[" && tmp != "]") {
			return "invalid";
		}
		else if (tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/" && tmp != "%") {
			mystack.push(tmp);
		}
		else {
			if (mystack.size() < 2) {
				return "invalid";
			}
			else {
				tmp2 = mystack.top();
				mystack.pop();
				tmp3 = mystack.top();
				mystack.pop();
				tmp4 = tmp3 + " " + tmp + " " + tmp2;
				tmp4 = "( " + tmp4 + " )";
				mystack.push(tmp4);
				//ss.str();
			} 
		}
		if (mystack.empty()) {
			return "invalid";
		}
	}
	if (mystack.size() > 1) {
		return "invalid";
	}
	else {
		return mystack.top();
	}
}


string ExpressionManager::postfixEvaluate(string postfixExpression) {
	stack <int> mystack;
	stringstream ss(postfixExpression);
	string tmp;
	int tmp2, tmp3, tmp4;

	while (!ss.eof()) {
		ss >> tmp;

		if (tmp == "+") {
			if (mystack.size() < 2) {
				return "invalid";
			}
			else {
				tmp2 = mystack.top();
				mystack.pop();
				tmp3 = mystack.top();
				mystack.pop();
				tmp4 = tmp3 + tmp2;
				mystack.push(tmp4);
				
			}
		}
		else if (tmp == "-") {
			if (mystack.size() < 2) {
				return "invalid";
			}
			else {
				tmp2 = mystack.top();
				mystack.pop();
				tmp3 = mystack.top();
				mystack.pop();
				tmp4 = tmp3 - tmp2;
				mystack.push(tmp4);

			}
		}
		else if (tmp == "*") {
			if (mystack.size() < 2) {
				return "invalid";
			}
			else {
				tmp2 = mystack.top();
				mystack.pop();
				tmp3 = mystack.top();
				mystack.pop();
				tmp4 = tmp3 * tmp2;
				mystack.push(tmp4);

			}
		}
		else if (tmp == "/") {
			if (mystack.size() < 2) {
				return "invalid";
			}
			else {
				tmp2 = mystack.top();
				mystack.pop();
				tmp3 = mystack.top();
				mystack.pop();
				if (tmp2 == 0) {
					return "invalid";
				}
				tmp4 = tmp3 / tmp2;
				mystack.push(tmp4);

			}
		}
		else if (tmp == "%") {
			if (mystack.size() < 2) {
				return "invalid";
			}
			else {
				tmp2 = mystack.top();
				mystack.pop();
				tmp3 = mystack.top();
				mystack.pop();
				if (tmp2 == 0) {
					return "invalid";
				}
				tmp4 = tmp3 % tmp2;
				mystack.push(tmp4);

			}
		}
		else {
			if (!all_of(tmp.begin(), tmp.end(), ::isdigit)) {
				return "invalid";
			}
			int stringNum = stoi(tmp, nullptr);
			mystack.push(stringNum);
		}
	}
		string numString = to_string(mystack.top());
		return numString;
}

string ExpressionManager::infixToPostfix(string infixExpression) {
	stack <string> mystack;
	stringstream ss(infixExpression);
	string postfix;
	string tmp;

	while (!ss.eof()) {
		ss >> tmp;
		if (!(all_of(tmp.begin(), tmp.end(), ::isdigit))
			&& tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/" && tmp != "%"
			&& tmp != "{" && tmp != "}" && tmp != "(" && tmp != ")" && tmp != "[" && tmp != "]") {
			return "invalid";
		}
		else if (all_of(tmp.begin(), tmp.end(), ::isdigit)) {
			postfix = postfix + " " + tmp;
		}
		else if (getPresedence(tmp) == 0) {
			mystack.push(tmp);
		}
		else if (getPresedence(tmp) == 1) {
			if (mystack.empty() || getPresedence(mystack.top()) == 0) {
				if (postfix == "") {
					return "invalid";
				}
				else {
					mystack.push(tmp);
				}
			}
			else if (getPresedence(mystack.top()) == 1) {
					postfix = postfix + " " + mystack.top();
					mystack.pop();
					mystack.push(tmp);
			}
			else if (getPresedence(mystack.top()) > 1) {
				while (!mystack.empty() && getPresedence(mystack.top()) >= 1) {
					postfix = postfix + " " + mystack.top();
					mystack.pop();
				}
				mystack.push(tmp);
			}
		}
		else if (getPresedence(tmp) == 2) {
			if (mystack.empty() || getPresedence(mystack.top()) == 0 || getPresedence(mystack.top()) == 1) {
				mystack.push(tmp);
			}
			else if (getPresedence(mystack.top()) == 2) {
				postfix = postfix + " " + mystack.top();
				mystack.pop();
				mystack.push(tmp);
			}
			else if (getPresedence(mystack.top()) > 2) {
				postfix = postfix + " " + tmp;
			}
		}
		else if (getPresedence(tmp) == 3) {
			if (mystack.empty()) {
				return "invalid";
			}
			if (tmp == ")") {
				while (mystack.top() != "(") {
					postfix = postfix + " " + mystack.top();
					mystack.pop();
				}
				mystack.pop();
			}
			else if(tmp == "]") {
				while (mystack.top() != "[") {
					postfix = postfix + " " + mystack.top();
					mystack.pop();
				}
				mystack.pop();
			}
			else if (tmp == "}") {
				while (!mystack.empty() && mystack.top() != "{") {
					postfix = postfix + " " + mystack.top();
					mystack.pop();	
				}
				if (mystack.empty()) {
					return "invalid";
				}
				else {
					mystack.pop();
				}
			}
			else {
				return "invalid";
			}
		}
	}
	while (!mystack.empty()) {
		if (mystack.top() != "+" && mystack.top() != "-" && mystack.top() != "*"
			&& mystack.top() != "/" && mystack.top() != "%") {
			return "invalid";
		}
		else {
			postfix = postfix + " " + mystack.top();
			mystack.pop();
		}
	}
	if (postfix == "") {
		return "invalid";
	}
	else if (postfix == "-") {
		return "invalid";
	}
	else {
		if (postfixToInfix(postfix) == "invalid") {
			return "invalid";
		}
		else {
			postfix.erase(postfix.begin());
			return postfix;
		}
	}
}

int ExpressionManager::getPresedence(string str) {
	if (str == ")" || str == "}" || str == "]") {
		return 3;
	}
	if (str == "*" || str == "/" || str == "%") {
		return 2;
	}
	if (str == "+" || str == "-") {
		return 1;
	}
	if (str == "(" || str == "{" || str == "[") {
		return 0;
	}
}
