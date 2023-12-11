// Copyright 2022 CSCE40-003
// 2022-10-04 - Program Assignment 3
// Andrew Davison
#include "word_search_functions.h"
#include <string>
#include <fstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
int CharCount(string file_name) {
  ifstream my_file(file_name);
  char letter;
  int count = 0;
  my_file >> letter;
  while (my_file.good()) {
    my_file >> letter;
    count++;
  }
  return count;
}
bool ReadWordSearch(string file_name, char word_search[][kSize]) {
  ifstream my_file(file_name);
  int count = CharCount(file_name);
  if (count < (kSize * kSize)) {
    return false;
  }
  while (my_file.good()) {
    for (int i = 0; i < kSize; i++) {
      for (int j = 0; j < kSize; j++) {
        my_file >> word_search[i][j];
      }
    }
  }
  return true;
}
void PrintWordSearch(const char word_search[][kSize]) {
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      cout << word_search[i][j] << " ";
    }
    cout << endl;
  }
}
Position FindWordRight(const char word_search[][kSize], string to_find) {
  Position pos = {};
  pos.row = -1;
  pos.col = -1;
  for (int i = 0; i < kSize; i++) {  // loop thru rows
    for (int j = 0; j < kSize; j++) {  // loop thru cols
      if (word_search[i][j] == to_find[0]) {  // if current pos = first letter
        int k = 0;
        while (k < static_cast<int>(to_find.length()) &&
            word_search[i][j+k] == to_find[k] && (j+k) <= kSize-1) {
          // while we are less than word, compare matrix values and word
          k++;
        }
        if (k == static_cast<int>(to_find.length())) {
          pos.row = i;
          pos.col = j;
          return pos;
        }
      }
    }
  }
  return pos;
}
Position FindWordLeft(const char word_search[][kSize], string to_find) {
  Position pos = {};
  pos.row = -1;
  pos.col = -1;
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      if (word_search[i][j] == to_find[0]) {
        int k = 0;
        while (k < static_cast<int>(to_find.length()) &&
            word_search[i][j-k] == to_find[k] && (j-k) >= 0) {
          k++;
        }
        if (k == static_cast<int>(to_find.length())) {
          pos.row = i;
          pos.col = j;
          return pos;
        }
      }
    }
  }
  return pos;
}
Position FindWordDown(const char word_search[][kSize], string to_find) {
  Position pos = {};
  pos.row = -1;
  pos.col = -1;
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      if (word_search[i][j] == to_find[0]) {
        int k = 0;
        while (k < static_cast<int>(to_find.length()) &&
            word_search[i+k][j] == to_find[k]) {
          k++;
        }
        if (k == static_cast<int>(to_find.length())) {
          pos.row = i;
          pos.col = j;
          return pos;
        }
      }
    }
  }
  return pos;
}
Position FindWordUp(const char word_search[][kSize], string to_find) {
  Position pos = {};
  pos.row = -1;
  pos.col = -1;
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      if (word_search[i][j] == to_find[0]) {
        int k = 0;
        while (k < static_cast<int>(to_find.length()) &&
            word_search[i-k][j] == to_find[k]) {
          k++;
        }
        if (k == static_cast<int>(to_find.length())) {
          pos.row = i;
          pos.col = j;
          return pos;
        }
      }
    }
  }
  return pos;
}
Position FindWordDiagonal(const char word_search[][kSize], string to_find) {
  Position pos = {};
  pos.row = -1;
  pos.col = -1;
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      if (word_search[i][j] == to_find[0]) {
        int k = 0;
        while (k < static_cast<int>(to_find.length()) &&
          word_search[i+k][j+k] == to_find[k]) {
          k++;
        }
        if (k == static_cast<int>(to_find.length())) {
          pos.row = i;
          pos.col = j;
          return pos;
        }
      }
    }
  }
  return pos;
}
