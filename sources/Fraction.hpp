#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel {

    class Fraction {
        private:
            int numerator;
            int denominator;
            int number;

        public:
            Fraction();
            Fraction(int numerator, int denominator);
            Fraction(float number);

            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;

            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;

            Fraction operator++();    // pre-increment
            Fraction operator++(int); // post-increment
            Fraction operator--();    // pre-decrement
            Fraction operator--(int); // post-decrement

            friend std::ostream& operator<<(std::ostream& outs, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& ins, Fraction& fraction);

            friend Fraction operator+(float, const Fraction& other);
            friend Fraction operator-(float, const Fraction& other);
            friend Fraction operator*(float, const Fraction& other);
            friend Fraction operator/(float, const Fraction& other);

            friend bool operator==(float, const Fraction& other);
            friend bool operator!=(float, const Fraction& other);
            friend bool operator>(float, const Fraction& other);
            friend bool operator<(float, const Fraction& other);
            friend bool operator>=(float, const Fraction& other);
            friend bool operator<=(float, const Fraction& other);
    };
}

#endif /* FRACTION_HPP */