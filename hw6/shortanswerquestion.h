// Copyright 2022 CSCE240
// Andrew Davison
#ifndef _SHORTANSERQUESTION_H_
#define _SHORTANSWERQUESTION_H_

#include "question.h"
#include <string>
using std::string;

namespace csce240_program6 {

// ShortAnswerQuestion should be a child of the Question class
class ShortAnswerQuestion : public Question {

// The class should have a private string data member that holds the correct
// answer to the question. Add an accessor and mutator function for this data
// member
 private:
  string correct_answer_;
// Create an explicit constructor that allows the question and answer to be
// initialized when instantiated. The question and answer parameters should
// have default arguments of "?" and "", respectively.
 public:
  explicit ShortAnswerQuestion(string = "?", string = "");
// Add a virtual Print function (see the Question class for the prototype)
// This fuction should create 1 or 2 lines of output to the standard output
// device, using cout.
// The first line of output should be "Question: " followed by the value of
// the question data member.
// If the Print function's argument is true, it should output a second line
// that is "Correct Answer: " followed by the value of the correct answer
// private data member.
  virtual void Print(bool include_correct_answer) const;

  void SetCorrectAnswer(string answer);
  string GetCorrectAnswer() const { return correct_answer_; }
};

}  // end namespace csce240_program6

#endif  // _SHORTANSWERQUESTION_H_
