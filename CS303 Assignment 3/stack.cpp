#include <string>
#include <stack>
#include <iostream>
#include "stack.h"

using namespace std;

bool Infix::isOperator(char input) {
    // Check to see if given input is an operator. If so, return true.
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '^') {
        return true;
    }
    else {
        return false;
    }
}

bool Infix::isOperand(char input) {
    // Check to see if given input is an operand. If so, return true.
    if (input >= '0' && input <= '9') {
        return true;
    }
    else if (input >= 'A' && input <= 'Z') {
        return true;
    }
    else if (input >= 'a' && input <= 'z') {
        return true;
    }
    else {
        return false;
    }
}

bool Infix::greaterOrEqual(char operand1, char operand2) {
    // See if the first given operand is of higher priority than the second.
    int priority1 = priority(operand1);
    int priority2 = priority(operand2);

    if (priority1 == priority2) {
        if (operand1 == '^') {
            return false;
        }
        return true;
    }
    return (priority1 > priority2 ? true : false);
}

int Infix::priority(char operand) {
    // Plus and minus have the lowest priority.
    if (operand == '+' || operand == '-') {
        return 1;
    }
    // Multiplication and division are second.
    if (operand == '*' || operand == '/') {
        return 2;
    }
    // Exponents are the highest.
    if (operand == '^') {
        return 3;
    }
    return 0;
}

string Infix::convertToPostfix(string infix) {
    // :(
    stack <char> S; // Initalize stack
    string postfix = ""; 
    char ch; // Grab each part of the string that we iterate through.

    S.push('(');
    infix += ')';

    for (int i = 0; i < infix.length(); i++) {
        ch = infix[i];

        if (ch == ' ') { // If our current part of the infix statement is blank, skip it.
            continue;
        }
        else if (ch == '(') { // If it's an open parenthesis, immediately push it to the stack.
            S.push(ch);
        }
        else if (isOperand(ch)) { // If it's an operand, add it to the postfix statement immediately. 
            postfix += ch;
        }
        else if (isOperator(ch)) { // If it's an operator...
            while (!S.empty() && greaterOrEqual(S.top(), ch)) { // While stack isn't empty and this operator has a lesser priority to the top of the stack...
                postfix += S.top(); // Add the top of the stack to our postfix statement.
                S.pop(); // And pop the top.
            }
            S.push(ch); // Push that operand to the stack, as it'll be used later.
        }
        else if (ch == ')') { // If our character is a closing parenthesis...
            while (!S.empty() && S.top() != '(') { // While our stack isn't empty and the top of our stack isn't an open parenthesis...
                postfix += S.top(); // Add the top of our stack to the postfix
                S.pop(); // And pop the top.
            }
            S.pop(); // As well as popping the final part of the stack, as that'll be the end of our postfix statement.
        }
    }
    return postfix; // 
}