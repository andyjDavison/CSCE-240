// Copyright 2022 CSCE240-003
// 2022-09-13 - Program Assignment 2
// Andrew Davison
#include"operator_functions.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

int main() {
  double l, r, answer = 0;
  char op;
  // Make file input object and call it my_file
  ifstream my_file("arithmetic_expressions.txt");
  my_file >> l >> op >> r;
  while (my_file.good()) {
   /* if (Compute(l, op, r, answer)) {
     Compute(l, op, r, answer);
     cout << l << OperatorToWords(op) << r << " equals " << answer << endl;
    }*/
    Compute(l, op, r, answer);
    // Get the nex line in file
    my_file >> l >> op >> r;
  }
  return 0;
}
