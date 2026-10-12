#include <iostream>
#include <cmath>

int main(){
    double a, b, c;
    bool valid = false;
    std::string type;

    std::cout << "Enter three side lengths: ";
    std::cin >> a >> b >> c;
    // Check whether the sides form a valid triangle

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        valid = true;
    }

    // If valid:
    if (a == b && b == c) {
        type = "equilateral";
    }
    else if (a == b || a == c || b == c) {
        type = "isoceles";
    }
    else {type = "scalene";}

    //   Determine and display the type of triangle

    double per = a + b + c;
    //   Calculate and display the perimeter

    double semip = 1.0/2.0 * (a + b + c);

    double area = std::sqrt(semip * (semip - a) * (semip - b) * (semip - c));
    //   Calculate and display the area using Heron's formula


    if (valid) {
        std::cout << "Type: " << type << std::endl;
        std::cout << "Perimeter: " << per << std::endl;
        std::cout << "Area: " << area << std::endl;
    }

    else {
        std::cout << "Invalid" << std::endl;
    }
    // Otherwise:
    //   Display a message saying the triangle is invalid
}