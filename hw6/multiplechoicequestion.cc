// Copyright 2022 CSCE240
// Andrew Davison

#include"question.h"
#include"multiplechoicequestion.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

namespace csce240_program6 {

MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int num,
  string *choice, bool *correct) : Question(q) {
    SetAnswerChoices(num, choice, correct);
}
MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion
  &to_copy) : Question(to_copy.GetQuestion()) {
    SetAnswerChoices(to_copy.num_, to_copy.choices_, to_copy.correct_);
}
void MultipleChoiceQuestion::SetNumberOfAnswerChoices(int num) {
    if (num < 0) {
        num_ = 0;
    } else {
        num_ = num;
    }
}
void MultipleChoiceQuestion::SetAnswerChoices(int num,
  string *choice, bool *correct) {
    SetNumberOfAnswerChoices(num);
    if (choice == nullptr && correct == nullptr) {
        return;
    }
    if (choice != nullptr) {
        delete [] choices_;
        choices_ = new string[num_];
        for (int i=0; i < num_; i++) {
            choices_[i] = choice[i];
        }
    }
    if (correct != nullptr) {
        delete [] correct_;
        correct_ = new bool[num_];
        for (int i=0; i < num_; i++) {
            correct_[i] = correct[i];
        }
    }
    if (choice != nullptr && correct == nullptr) {
        delete [] correct_;
        correct_ = new bool[num_];
        for (int i=0; i < num_; i++) {
            correct_[i] = true;
        }
    }
}
void MultipleChoiceQuestion::Print(bool include_correct_answer) const {
    cout << "Question: " << GetQuestion() << endl;
    cout << "Answer Choices:" << endl;
    string correctans;
    if (include_correct_answer) {
        for (int i=0; i < num_; i++) {
            correctans = (correct_[i] ? " - correct" : " - incorrect");
            cout << choices_[i] << correctans << endl;
        }
    } else if (!include_correct_answer) {
        for (int i=0; i < num_; i++) {
            cout << choices_[i] << endl;
        }
    }
}
MultipleChoiceQuestion::~MultipleChoiceQuestion() {
    delete [] choices_;
    delete [] correct_;
}
}  // end namespace csce240_program6
