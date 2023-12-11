// Copyright 2022 CSCE240-003
// 2022-10-14 - Program Assignment 4
// Andrew Davison
#include"taxid.h"
#include<string>
#include<regex>

using std::string;
using std::regex;

string TaxId::mask_ = "XXXXX####";
// initialize mask to "XXXXX####"
TaxId::TaxId() {
  id_ = "000000000";
}
TaxId::TaxId(string id) {
  SetId(id);
}
// implement the TaxId class' member functions
void TaxId::SetId(string id) {
  if (id.length() == 9) { // Check for length of id
    for (int i = 0; i < static_cast<int>(id.length()); i++) {
      // Check for letters in id
      if (!std::regex_match(id.substr(i,1), regex("[a-z]"))) {
        id_ = id;
      }
    }
  } else {
    // Check for dashes in id
    if (id[3] == '-' && id[6] == '-') {
      id_ = id.substr(0,3) + id.substr(4,2) + id.substr(7,4);
    }
  }
}
void TaxId::SetMask(string m) {
  bool flag = true;
  for (int i = 0; i < static_cast<int>(m.length()); i++) {
    if (m[i] != 'X' || m[i] != '#') {
      flag = false;
    }
  }
  if (!flag) {
    if (m.length() == 9) {
      mask_ = m;
    }
  }
}
string TaxId::GetId() {
  for (int i = 0; i < static_cast<int>(mask_.length()); i++) {
    if (mask_[i] == 'X') {
      id_[i] = 'X';
    }
  }
  return id_;
}
string TaxId::GetMask() {
  return mask_;
}
