#include <iostream>
#include <stdexcept>

int main() {
    int n, i = 0, maxn = 1;

    std::cout << "Please enter a number: " << std::endl;
    std::cin >> n;

    if (n <= 0) {
        throw std::runtime_error("Number is negative");
    }

    while (n != 1) {
        if (n > maxn) {
            maxn = n;
        }

        if ((n % 2) == 0) {
            n /= 2;
        }

        else {
            n = 3*n + 1;
        }

        std::cout << n << std::endl;
        i++;
    }

    std::cout << "Steps: " << i << std::endl;
    std::cout << "Max number: " << maxn << std::endl;
    return 0;
}