// Copyright 2022 CSCE240
// Andrew Davison

#include"probability.h"
#include<string>

using std::string;

namespace csce240_program5 {
// implement Probability class functionality here
    Probability::Probability(int n, int d) : Fraction(n, d),
    num_(0), denom_(1) {
        if (IsValidProb(n, d)) {
            SetNumerator(n);
            SetDenominator(d);
        } else {
            SetNumerator(0);
            SetDenominator(1);
        }
    }
    Probability::Probability(Fraction const &frac) {
        if (IsValidProb(frac.GetNumerator(), frac.GetDenominator())) {
            SetNumerator(frac.GetNumerator());
            SetDenominator(frac.GetDenominator());
        } else {
            SetNumerator(0);
            SetDenominator(1);
        }
    }
    void Probability::SetNumerator(int n) {
        num_ = n;
    }
    void Probability::SetDenominator(int d) {
        denom_ = d;
    }
    bool Probability::operator== (Probability const &prob) const {
        if (num_*(prob.GetDenominator()) == (prob.GetNumerator())*denom_) {
            return true;
        } else {
            return false;
        }
    }
    Probability Probability::operator* (Probability const &prob) const {
        Probability p;
        p.SetNumerator(num_*(prob.GetNumerator()));
        p.SetDenominator(denom_*(prob.GetDenominator()));
        return p;
    }
    bool Probability::IsValidProb(int n, int d) {
        if (n < d && n >= 0 && d > 0) {
            return true;
        } else {
            return false;
        }
    }
    void Probability::Multiply(int num) {
        if (IsValidProb(num*GetNumerator(), GetDenominator())) {
            SetNumerator(num*GetNumerator());
        }
    }
    void Probability::Divide(int num) {
        if (num != 0 && IsValidProb(GetNumerator(), num*GetDenominator())) {
            SetDenominator(num*denom_);
        }
    }
    string Probability::OddsInFavor() const {
        int odds = GetDenominator()-GetNumerator();
        return std::to_string(GetNumerator()) + ":" + std::to_string(odds);
    }
}  // end namespace csce240_program5
