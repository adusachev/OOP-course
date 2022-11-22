#include <iostream>


struct Rational {

    Rational(int numerator = 0, int denominator = 1) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }


    double to_double() const {
        return numerator_ / (double)denominator_;
    }

    Rational& operator+=(Rational rational) {
        this->add(rational);
        return *this;
    }

    Rational& operator-=(Rational rational) {
        this->sub(rational);
        return *this;
    }

    Rational& operator*=(Rational rational) {
        this->mul(rational);
        return *this;
    }

    Rational& operator/=(Rational rational) {
        this->div(rational);
        return *this;
    }

    Rational operator-() const {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }

    Rational operator+() const {
        Rational r(this->numerator_, this->denominator_);
        return r;
    }

    friend bool operator==(Rational const& lhs, Rational const& rhs) {
        return (lhs.numerator_ * rhs.denominator_  == lhs.denominator_ * rhs.numerator_);
    }

    friend bool operator!=(Rational const& lhs, Rational const& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator>(Rational const& lhs, Rational const& rhs) {
        return (lhs.numerator_ * rhs.denominator_  > lhs.denominator_ * rhs.numerator_);
    }

    friend bool operator<=(Rational const& lhs, Rational const& rhs) {
        return !(lhs > rhs);
    }

    friend bool operator<(Rational const& lhs, Rational const& rhs) {
        return (!(lhs > rhs) && (lhs != rhs));
    }

    friend bool operator>=(Rational const& lhs, Rational const& rhs) {
        return !(lhs < rhs);
    }


    operator double() const { 
        return this->to_double();
    }



private:
    int numerator_;
    int denominator_;
};




Rational operator+(Rational lhs, Rational rhs) {
    Rational res;
    res += lhs;
    res += rhs;
    return res;
}

Rational operator-(Rational lhs, Rational rhs) {
    Rational res;
    res += lhs;
    res -= rhs;
    return res;
}

Rational operator*(Rational lhs, Rational rhs) {
    Rational res;
    res += lhs;
    res *= rhs;
    return res;
}

Rational operator/(Rational lhs, Rational rhs) {
    Rational res;
    res += lhs;
    res /= rhs;
    return res;
}








int main() {
    Rational r1(1, 3);
    Rational r2(1, 2);
    Rational r3(5);

    // r1 *= r2;

    // r1.add(r2);
    // cout << (r1+r2).to_double() << endl;
    bool ans = (r1 > r2);
    std::cout << ans << std::endl;

    std::cout << (double)r1 << std::endl;
    // r1.sub(r2);
    // cout << r1.to_double() << endl;
    // r1.neg();
    // cout << r1.to_double() << endl;
    // r3.mul(r1);
    // cout << r3.to_double() << endl;
    // r3.div(r2);
    // cout << r3.to_double() << endl;



    return 0;
}
