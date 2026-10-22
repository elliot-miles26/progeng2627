#include <iostream>
#include <cmath>

double mypow(double base, int power) {
    double result = 1;
    for (int i = 1; i <= power; i++) {
        result *= base;
    }

    return result;
}

double sum_powers(double x, int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        result += mypow(x, i);        
    }

    return result;
}

int main() {
    double x;
    int n;
    std::cout << "Enter x: " << std::endl;
    std::cin >> x;

    std::cout << "Enter n: " << std::endl;
    std::cin >> n;

    std::cout << sum_powers(x, n) << std::endl;

    return 0;
}