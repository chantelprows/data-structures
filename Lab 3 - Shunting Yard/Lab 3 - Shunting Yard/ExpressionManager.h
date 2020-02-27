#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "ExpressionManagerInterface.h"

using namespace std;


class ExpressionManager : public ExpressionManagerInterface
{
public:
	ExpressionManager() {}
	virtual ~ExpressionManager() {}

	virtual bool isBalanced(string expression);

	virtual string postfixToInfix(string postfixExpression);

	virtual string postfixEvaluate(string postfixExpression);

	virtual string infixToPostfix(string infixExpression);

private:

	int getPresedence(string str);

};