#include <iostream>

int smallest_factor(int n) {
    for(int cf = 2; cf < n; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...

            return cf;
            //...it means we have found a factor!
        }
    }

    return 0;
}

int main() {
    int n;
    std::cout << "Input n: " << std::endl;
    std::cin >> n;

    int f = smallest_factor(n);

    if (f == 0) {
        std::cout << "n is prime" << std::endl;
    }

    else {
        std::cout << "Smallest factor: " << f << std::endl;
    }


    return 0;
}