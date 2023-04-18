#pragma once

#include <string>
#include <stack>

using namespace std;

class Infix {
public:

    bool isOperator(char input);
    bool isOperand(char input);
    bool greaterOrEqual(char operand1, char operand2);

    int priority(char operand);

    string convertToPostfix(string infix);


private:
    string infix, postfix;
};