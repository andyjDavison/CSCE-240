// Copyright 2022 Andrew Davison
#include <string>
using std::string;
// function to take a double returns whether or not the truncated
// integer is the same as the double
// preconditions: function expects one double
// postconditions: returns true if the truncated integer equals the
// double we passed in
bool IsInteger(double a);

// function to take a single character and return whether that
// character represents a mathematical operator
// preconditions: function expects one character
// postconditions: return true if the character represents a
// math operator, else returns false
bool IsArithmeticOperator(char a);

// function to take a single char and change the char to a full string
// preconditions: functions expects one character
// postconditions: return the full string a math character
string OperatorToWords(char a);

// function to take the operand on the left and right, and the operator
// in the middle and compute an answer
// preconditions: function expects 3 doubles, and one character
// postconditions: returns true if the operator is valid and sets answer
// to computed value, or false if the operator is not valid
bool Compute(double left, char op, double right, double &answer);
