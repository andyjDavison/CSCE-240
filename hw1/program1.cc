// Copyright 2022 CSCE240-003
// 2022-08-26 - Program Assignment 1
// Andrew Davison

#include<cmath>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
  // Get input
  int num, base;
  cin >> num >> base;
  int decimal, digit, count = 0;
  decimal = count;
  bool pass = true;
  // Check if base is valid
  if (base >=2 && base <= 9) {
    // Loop thru num and convert each digit to decimal
    while (num != 0) {
      digit = num % 10;
      // Check if digit is valid for base
      if (digit < base) {
        num /= 10;
        // Convert to base by powers
        decimal += digit*pow(base, count);
        count++;
      } else {
          cout << "Invalid Digit(s) In Number" << endl;
          pass = false;
          break;
        }
    }
  } else {
    cout << "Base Not Accepted" << endl;
    pass = false;
  }
  if (pass)
    cout << decimal << endl;
}
