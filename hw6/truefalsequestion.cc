// Copyright 2022 CSCE240
// Andrew Davison

#include"question.h"
#include"truefalsequestion.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

namespace csce240_program6 {

TrueFalseQuestion::TrueFalseQuestion(string q, bool a) : Question(q) {
    SetCorrectAnswer(a);
}
void TrueFalseQuestion::SetCorrectAnswer(bool a) {
    answer_ = a;
}
void TrueFalseQuestion::Print(bool include_correct_answer_) const {
    cout << "Question: " << GetQuestion() << endl;
    if (include_correct_answer_) {
        string ans = (GetCorrectAnswer() ? "true" : "false");
        cout << "Correct Answer: " << ans << endl;
    }
}
}  // end namespace csce240_program6
