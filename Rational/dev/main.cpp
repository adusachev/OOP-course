#include <iostream>


struct Rational {

    Rational(int numerator = 0, int denominator = 1) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    // basic methods
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

    // overload arithmetic operatos
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

    // overload bool operators
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



// overload arithmetic operatos
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





// tests
void test_base_methods() {
   Rational r1(1, 2);
   Rational r2(1, 3);
   Rational r3(5);

   r1.add(r2);
   std::cout << r1.to_double() << std::endl;
   r1.sub(r2);
   std::cout << r1.to_double() << std::endl;
   r1.neg();
   std::cout << r1.to_double() << std::endl;
   r3.mul(r1);
   std::cout << r3.to_double() << std::endl;
   r3.div(r2);
   std::cout << r3.to_double() << std::endl;
}


void test_operators() {
   Rational r1(1, 2);
   Rational r2(1, 3);
   std::cout << "r1: " << r1.to_double() << "; r2: " << r2.to_double() << std::endl;

   r1 += r2;
   std::cout << r1.to_double() << std::endl;

   r1 -= r2;
   std::cout << r1.to_double() << std::endl;

   r1 *= r2;
   std::cout << r1.to_double() << std::endl;

   r1 /= r2;
   std::cout << r1.to_double() << std::endl;

   std::cout << (-r1).to_double() << std::endl;
}

void test_bool_operators() {
   Rational r1(1, 2);
   Rational r2(1, 3);
   std::cout << "r1: " << r1.to_double() << "; r2: " << r2.to_double() << std::endl;

   std::cout << (r1 == r2) << std::endl;
   std::cout << (r1 != r2) << std::endl;
   std::cout << (r1 > r2) << std::endl;
   std::cout << (r1 <= r2) << std::endl;
}

void test_arithm_operations() {
   Rational r1(1, 2);
   Rational r2(1, 3);
   std::cout << "r1: " << r1.to_double() << "; r2: " << r2.to_double() << std::endl;
   {
       Rational r3 = r1 + r2;
       std::cout << "sum: " << r3.to_double() << std::endl;
   }
   {
       Rational r3 = r1 - r2;
       std::cout << "diff: " << r3.to_double() << std::endl;
   }
   {
       Rational r3 = r1 * r2;
       std::cout << "mult: " << r3.to_double() << std::endl;
   }
   {
       Rational r3 = r1 / r2;
       std::cout << "ratio: " << r3.to_double() << std::endl;
   }
}




int main() {
    
    // test_base_methods();
    // test_operators();
    // test_bool_operators();
    test_arithm_operations();


    return 0;
}
