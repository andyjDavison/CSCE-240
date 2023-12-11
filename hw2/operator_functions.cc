// Copyright 2022 CSCE240
#include "operator_functions.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;
using std::endl;
bool IsInteger(double a) {
  // Cast to int and check against old double value
  int b = static_cast<int>(a);
  return a == b;
}
bool IsArithmeticOperator(char a) {
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '%');
}
string OperatorToWords(char a) {
  switch (a) {
    case '+':
      return " plus ";
      break;
    case '-':
      return " minus ";
      break;
    case '*':
      return " times ";
      break;
    case '/':
      return " divided by ";
      break;
    case '%':
      return " modulo ";
      break;
    default:
      return " ?? ";
  }
}
bool Compute(double left, char op, double right, double& answer) {
  answer = 0;
  // Check if the operator is valid, otherwise return false
  if (IsArithmeticOperator(op)) {
    if (op == '+') {
      answer = left + right;
    } else if (op == '-') {
      answer = left - right;
    } else if (op == '*') {
      answer = left * right;
    } else if (op == '/') {
      // Check if the divison statement is possible, if not return false
      if (right == 0) {
        cout << "Could not compute " << left <<
          OperatorToWords(op) << right << endl;
        return false;
      }
      answer = left / right;
    } else if (op == '%') {
      // Check if the modulo statement is possible, if not return false
      if (!IsInteger(left) || !IsInteger(right) || right == 0) {
        cout << "Could not compute " << left <<
          OperatorToWords(op) << right << endl;
        return false;
      }
      answer = static_cast<int>(left) % static_cast<int>(right);
    }
    cout << left << OperatorToWords(op) <<
      right << " equals " << answer << endl;
    return true;
  }
  cout << "Unrecognized operation " << op << endl;
  return false;
}
