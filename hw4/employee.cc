// Copyright 2022 CSCE240 Andrew Davison
// Implementing Employee Class
#include"employee.h"
#include"taxid.h"
#include<string>

using std::string;

// Default Constructor
Employee::Employee() {
  TaxId taxid_;
  string id_ = "999999999";
  SetTaxId(id_);
  hours_ = 40.0;
  pay_type_ = 1;
}
Employee::Employee(string t, int p, double h) {
  SetTaxId(t);
  SetHoursPerWeek(h);
  SetPayType(p);
}

void Employee::SetTaxId(string t) {
  taxid_.SetId(t);
}
void Employee::SetHoursPerWeek(double h) {
  if (h >= 0.0 && h <= 40.0) {
    hours_ = h;
  }
}
void Employee::SetPayType(int p) {
  if (p == 1 || p == 2 || p == 3) {
    pay_type_ = p;
  }
}
void Employee::SetPayType(string p) {
  if (p == "salaried") {
    pay_type_ = 1;
  } else if (p == "hourly") {
    pay_type_ = 2;
  } else if (p == "contract") {
    pay_type_ = 3;
  }
}
string Employee::GetTaxId() const {
  return id_;
}
double Employee::GetHoursPerWeek() const {
  return hours_;
}
string Employee::GetPayType() const {
  if (pay_type_ == 1) {
    return "salaried";
  } else if (pay_type_ == 2) {
    return "hourly";
  } else {
    return "contract";
  }
}

