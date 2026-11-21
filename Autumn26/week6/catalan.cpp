#include <iostream>
#include <vector>
#include <cmath>

// Write your functions here

std::vector<unsigned long> catalan_numbers(int n) {
    std::vector<unsigned long> nums;
    nums[0] = 1;
    for (int k = 1; k < n + 1; k++) {
        for (int i = 0; i < n; i++) {
            nums[k] += nums[i]*nums[n-1-i];
        }
    }
    return nums;
}

int main() {
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<unsigned long> numbers = catalan_numbers(n);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << "C" << i << " = " << numbers[i] << std::endl;
    }

    return 0;
}