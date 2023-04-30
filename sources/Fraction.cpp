#include "Fraction.hpp"
#include <stdexcept>

using namespace ariel;

// Default constructor
Fraction::Fraction() : numerator(0), denominator(1) {}

// Constructor with parameters
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
}
Fraction::Fraction(float number) : number(number){}

// Addition operator
Fraction Fraction::operator+(const Fraction& other) const {
    int new_numerator = numerator * other.denominator + other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

// Subtraction operator
Fraction Fraction::operator-(const Fraction& other) const {
    int new_numerator = numerator * other.denominator - other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

// Multiplication operator
Fraction Fraction::operator*(const Fraction& other) const {
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

// Division operator
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;
    return Fraction(new_numerator, new_denominator);
}

// Equality operator
bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

// Inequality operator
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

// Greater than operator
bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

// Less than operator
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

// Greater than or equal to operator
bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

// Less than or equal to operator
bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

// Pre-increment operator
Fraction Fraction::operator++() {
    numerator += denominator;
    return *this;
}

// Post-increment operator
Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    ++(*this);
    return temp;
}

// Pre-decrement operator
Fraction Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

// Post-decrement operator
Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    --(*this);
    return temp;
}

// Output stream operator
std::ostream& ariel::operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

// Input stream operator
std::istream& ariel::operator>>(std::istream& is, Fraction& fraction) {
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;
    if (fraction.denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    return is;
}


Fraction ariel::operator+(const float number, const Fraction& other) {
    int numerator_number = number * 100;
    int denominator_number = 100;
    int new_numerator = numerator_number * other.denominator + other.numerator * denominator_number;
    int new_denominator = denominator_number * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

Fraction ariel::operator-(const float number, const Fraction& other) {
    int numerator_number = number * 100;
    int denominator_number = 100;
    int new_numerator = numerator_number * other.denominator - other.numerator * denominator_number;
    int new_denominator = denominator_number * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

Fraction ariel::operator*(const float number, const Fraction& other) {
    int numerator_number = number * 100;
    int denominator_number = 100;
    int new_numerator = numerator_number * other.numerator;
    int new_denominator = denominator_number * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

Fraction ariel::operator/(const float number, const Fraction& other) {
    int numerator_number = number * 100;
    int denominator_number = 100;
    int new_numerator = numerator_number * other.numerator;
    int new_denominator = denominator_number * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

bool ariel::operator==(const float number, const Fraction& other) {
    return true;
}

bool ariel::operator!=(const float number, const Fraction& other) {
    return true;
}

bool ariel::operator>(const float number, const Fraction& other) {
    return true;
}

bool ariel::operator<(const float number, const Fraction& other) {
    return true;
}

bool ariel::operator>=(const float number, const Fraction& other) {
    return true;
}

bool ariel::operator<=(const float number, const Fraction& other) {
    return true;
}