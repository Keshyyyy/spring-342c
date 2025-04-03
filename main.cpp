#include <iostream>

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

void GCD(int num, int num2) {
    int temp = 0;
    int numerator = num;
    int denominator = num2;

    printf("%d/%d reduced is \n", numerator, denominator);

    while (num2 != 0) {
        temp = num2;
        num2 = num % num2;
        num = temp;
    }

    int gcd = num;

    numerator = numerator / gcd;
    denominator = denominator / gcd;

    std::cout << numerator << "/" << denominator << std::endl;


}

bool is_prime(int number) {
    if(number <= 1)
        return false;
    if (number % 2 == 0)
        return false;
    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }

    return true;

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

void test_prime_numbers(int num) {
    std::cout << "\nTesting prime number function" << std::endl;
    if (is_prime(num))
        printf("%d is a prime number - PASS\n", num);
    else
        printf("%d is not a prime number - FAIL\n", num);
}

int main() {
    test_power_of_two(16);
    test_prime_numbers(2);

    return 0;

}