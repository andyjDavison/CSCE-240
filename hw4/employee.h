// Copyright 2022 CSCE240 Andrew Davison
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "taxid.h"
#include<string>
using std::string;

class Employee {
 private:
  TaxId taxid_;
  string id_;
  double hours_;
  int pay_type_;
// Create a default constructor that creates an Employee object with defaults
// of 40 hours per week, hourly, and a TaxId of "999999999"
 public:
  // Default Constructor
Employee();
// Create a constructor that allows an Employee object to be created with
// specified initial values
// preconditions: The constructor will be sent a string for the tax id,
//                an integer for the pay type, and a double for the hours
//                per week
// postconditions: The private data members will be initialized with the values
//                 sent if they are valid.
//                 If the pay type argument is not 1, 2, or 3, the pay type
//                 data member will be set to 2.
//                 If the hours per week argument is not between 0 and 40,
//                 inclusive, then the hours per week data member will be
//                 set to 40.
Employee(string t, int p, double h);

// SetPayType mutator function
// preconditions: The function will be sent an integer which should be
//                1, 2, or 3
// postconditions: The private data member will be changed if the argument is
//                 valid. If the argument is invalid, the private data member
//                 will not be changed.
void SetPayType(int p);

// SetPayType mutator function 2
// preconditions: The function will be sent a string that should be either
//                "salaried" "hourly" or "contract"
// postconditions: If the argument is "salaried" the private data member will
//                 be set to 1.
//                 If the argument is "hourly" the private data member will
//                 be set to 2.
//                 If the argument is "contract" the private data member will
//                 be set to 3.
//                 If the argument is none of the above, the private data
//                 member will remain unchanged.
void SetPayType(string p);

// GetPayType accessor function will return the string "hourly" "salaried"
// or "contract" that corresponds to the private data member
string GetPayType() const;

// SetHoursPerWeek mutator function
// precondition: The function will be sent a double that should be between
//               0 and 40, inclusive
// postcondition: The function will update the data member to the value of the
//                argument if the argument is valid. Otherwise the data member
//                will remain unchanged.
void SetHoursPerWeek(double h);

// GetHoursPerWeek accessor function will return the employee's hours per week
double GetHoursPerWeek() const;

// SetTaxId mutator function - this function should take a string argument
// and send it to the set function written for the TaxId class
void SetTaxId(string t);

// GetTaxId accessor function - returns the tax id with all but the last
// four digits masked.
string GetTaxId() const;
};
#endif
