// Copyright 2022 CSCE240
// Andrew Davison

#include"question.h"
#include"shortanswerquestion.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

namespace csce240_program6 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) : Question(q) {
    SetCorrectAnswer(a);
}
void ShortAnswerQuestion::SetCorrectAnswer(string a) {
    correct_answer_ = a;
}
void ShortAnswerQuestion::Print(bool include_correct_answer) const {
    cout << "Question: " << GetQuestion() << endl;
    if (include_correct_answer) {
        cout << "Correct Answer: " << GetCorrectAnswer() << endl;
    }
}
}  // namespace csce240_program6
