#include <iostream>

class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {}
        std::string to_string() {
            return std::to_string(numerator) + "/" + std::to_string(denominator);
        }

        bool operator==(Fraction &other) {
            return this->numerator == other.numerator && this->denominator == other.denominator;
        }
};


bool power_of_two(int number);
bool power_of_two_noloop(int number);
bool is_prime(int number);
void reduce(int num, int num2);
void test_power_of_two(int num);
void test_prime_numbers();
void test_reduce();
Fraction reduce (Fraction input);

int main() {

    test_reduce();
    test_prime_numbers();

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
        std::cout << "Division by 0, fraction can't be reduced - FAIL" << std::endl;
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

void test_power_of_two(int num) {
    std::cout << "Testing power of two function using loops" << std::endl;
    if (power_of_two(num))
        printf("%d is a power of two - PASS\n", num);
    else
        printf("%d is not a power of two - FAIL\n", num);

    std::cout << "\nTesting power of two function using bitwise logic" << std::endl;
    if (power_of_two_noloop(num))
        printf("%d is a power of two - PASS\n", num);
    else
        printf("%d is not a power of two - FAIL\n", num);

}

void test_prime_numbers() {
    int inputs[5] = {2, 3, 4, 7, 12};
    bool expected[5] = {true, true, false, true, false};

    for (int i = 0; i < 5; i++) {
        int input = inputs[i];
        bool result = is_prime(input);
        if (result == expected[i]) {
            if (result == true)
                std::cout << "PASS! " << input << " is a prime number" << std::endl;
            else
                std::cout << "PASS! " << input << " is not a prime number" << std::endl;
        }
        else
            std::cout << "FAIL! At testcase " << i << " - expected was " << expected[i] <<
                " while actual was " << result << std::endl;
    }
}

void test_reduce() {
    Fraction inputs[4] = {Fraction(1,2), Fraction(2, 4),
                            Fraction(4, 2), Fraction(6, 8)};

    Fraction expected[4] = {Fraction(1, 2), Fraction(1, 2),
                            Fraction(2, 1), Fraction(3, 4)};

    for (int i = 0; i < 4; i++) {
        Fraction input = inputs[i];
        Fraction actual = reduce(inputs[i]);
        Fraction expect = expected[i];
        if (actual == expect)
            std::cout << "PASS! " << input.to_string() << " reduced is " << actual.to_string() << std::endl;

        else
            std::cout << "FAIL " << " Actual was " << actual.to_string() << "\nwhile expected was " << expect.to_string() << std::endl;
    }

}

