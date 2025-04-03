#include <iostream>

// Fraction class to have cleaner input output
class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {}
        // tostring function to print fractions
        std::string to_string() {
            return std::to_string(numerator) + "/" + std::to_string(denominator);
        }

        // == operator to make comparison easier
        bool operator==(Fraction &other) {
            return this->numerator == other.numerator && this->denominator == other.denominator;
        }
};


bool power_of_two(int number);
bool power_of_two_noloop(int number);
bool is_prime(int number);
void test_power_of_two();
void test_prime_numbers();
void test_reduce();
Fraction reduce (Fraction input);

int main() {

    test_reduce();
    std::cout << std::endl;

    test_prime_numbers();
    std::cout << std::endl;

    test_power_of_two();

    return 0;

}

bool power_of_two(int number) {
    if (number == 0)
        return false;
    while(number > 1){
        if(number % 2 == 0)
            number = number / 2;
        else
            return false;
    }
    return true;
}

bool power_of_two_noloop(int number) {
    if ((number > 0) && ((number & (number - 1)) == 0))
        return true;
    return false;
}

bool is_prime(int number) {
    if(number <= 1)
        return false;
    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }

    return true;

}

Fraction reduce (Fraction input) {
    if (input.denominator == 0) {
        std::cout << "Division by 0, fraction can't be reduced" << std::endl;
        return input;
    }
    int numerator = input.numerator;
    int denominator = input.denominator;
    int temp = 0;
    int gcd = 0;

    while (denominator != 0) {
        temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }

    gcd = numerator;
    numerator = input.numerator / gcd;
    denominator = input.denominator / gcd;

    return Fraction(numerator, denominator);


}

void test_power_of_two() {
    int inputs[6] = {1, 2, 16, 34, 60, 128};
    bool expected[6] = {true, true, true, false, false, true};

    std::cout << "Testing power of two function using a loop" << std::endl;
    for (int i = 0; i < 6; i++) {
        int input = inputs[i];
        bool actual = power_of_two(inputs[i]);
        bool expect = expected[i];

        if (actual == expect) {
            if (actual == true)
                std::cout << "PASS! " << input << " is a power of two" << std::endl;
            else
                std::cout << "PASS! " << input << " is not a power of two" << std::endl;
        }
        else
            std::cout << "FAIL! At testcase " << i << " - expected value was" <<
                expect << " while actual value was " << actual << std::endl;
    }

    int newInputs[6] = {2, 4, 6, 8, 127, 256};
    bool newExpected[6] = {true, true, false, true, false, true};

    std::cout << "\nTesting power of two function using bitwise logic" << std::endl;
    for (int i = 0; i < 6; i++) {
        int input = newInputs[i];
        bool actual = power_of_two_noloop(input);
        bool expect = newExpected[i];

        if (actual == expect) {
            if (actual == true)
                std::cout << "PASS! " << input << " is a power of two" << std::endl;
            else
                std::cout << "PASS! " << input << " is not a power of two" << std::endl;
        }
        else
            std::cout << "FAIL! At testcase " << i << " - expected value was" <<
                expect << " while actual value was " << actual << std::endl;
    }


}

void test_prime_numbers() {
    int inputs[5] = {2, 3, 4, 7, 12};
    bool expected[5] = {true, true, false, true, false};

    for (int i = 0; i < 5; i++) {
        int input = inputs[i];
        bool result = is_prime(input);
        bool expect = expected[i];
        if (result == expect) {
            if (result == true)
                std::cout << "PASS! " << input << " is a prime number" << std::endl;
            else
                std::cout << "PASS! " << input << " is not a prime number" << std::endl;
        }
        else
            std::cout << "FAIL! At testcase " << i << " - expected was " << expect <<
                " while actual was " << result << std::endl;
    }
}

void test_reduce() {
    Fraction inputs[6] = {Fraction(1,2), Fraction(2, 4),
                            Fraction(4, 2), Fraction(6, 8),
                            Fraction(-8, 2), Fraction(4, 0)};

    Fraction expected[6] = {Fraction(1, 2), Fraction(1, 2),
                            Fraction(2, 1), Fraction(3, 4),
                            Fraction(-4, 1), Fraction(4, 0)};

    for (int i = 0; i < 6; i++) {
        Fraction input = inputs[i];
        Fraction actual = reduce(inputs[i]);
        Fraction expect = expected[i];
        if (actual == expect)
            std::cout << "PASS! " << input.to_string() << " reduced is " << actual.to_string() << std::endl;

        else
            std::cout << "FAIL " << " Actual was " << actual.to_string() << "\nwhile expected was " << expect.to_string() << std::endl;
    }

}

