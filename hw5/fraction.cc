// Copyright 2022 CSCE240
// Andrew Davison
#include"fraction.h"
#include<string>

using std::string;

namespace csce240_program5 {
// implement Fraction class functionality here
    Fraction::Fraction(int n, int d) : num_(0), denom_(1) {
        SetNumerator(n);
        SetDenominator(d);
    }
    void Fraction::SetNumerator(int n) {
        num_ = n;
    }
    void Fraction::SetDenominator(int d) {
        if (d == 0) {
            denom_ = 1;
        } else {
            denom_ = d;
        }
    }
    bool Fraction::operator== (Fraction const &frac) const {
        if (num_*(frac.GetDenominator()) == (frac.GetNumerator())*denom_) {
            return true;
        } else {
            return false;
        }
    }
    double Fraction::ToDecimal() const {
        return static_cast<double>(GetNumerator())/
        static_cast<double>(GetDenominator());
    }
    void Fraction::Multiply(int num) {
        SetNumerator(num*num_);
    }
    void Fraction::Divide(int num) {
        if (num != 0) {
            SetDenominator(num*denom_);
        }
    }
    Fraction Fraction::operator* (Fraction const &frac) const {
        Fraction f;
        f.SetNumerator(num_*(frac.GetNumerator()));
        f.SetDenominator(denom_*(frac.GetDenominator()));
        return f;
    }
    string Fraction::ToString() const {
        return std::to_string(num_) + "/" + std::to_string(denom_);
    }
}  // end namespace csce240_program5
