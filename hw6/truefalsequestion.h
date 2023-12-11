// Copyright 2022 CSCE240
// Andrew Davison
#ifndef _TRUEFALSEQUESTION_H_
#define _TRUEFALSEQUESTION_H_

#include "question.h"
#include <string>
using std::string;

namespace csce240_program6 {
// TrueFalseQuestion should be a child of the Question class
class TrueFalseQuestion : public Question {
// The class should have a private bool data member that holds whether the
// answer to the question is true or false. Add an accessor and mutator
// function for this data member
 private:
  bool answer_;
// Create an explicit constructor that allows the question and answer to be
// initialized when an object is instantiated. The question and answer
// parameters should have default arguments of "?" and true, respectively.
 public:
  explicit TrueFalseQuestion(string = "?", bool = true);
// Add a virtual Print function (see the Question class for the prototype)
// This fuction should create 1 or 2 lines of output to the standard output
// device, using cout.
// The first line of output should be "Question: " followed by the value of
// the question data member.
// If the Print function's argument is true, it should output a second line
// that is "Correct Answer: " followed by "true" or "false" depending on the
// value of the private data member.
  virtual void Print(bool include_correct_answer) const;

  void SetCorrectAnswer(bool answer);
  bool GetCorrectAnswer() const { return answer_; }
};
}  // end namespace csce240_program6

#endif  // _TRUEFALSEQUESTION_H_
