#include <iostream>
#include <string>
#include <stdexcept>

double C_to_F(double C) {
    double F = (C * (9.0/5.0) + 32);
    return F;
}

double F_to_C(double F) {
    double C = ((F - 32) * (5.0/9.0));
    return C;
}

int main() {

    double temp_in, temp_out;
    std::string unit_in, unit_out;

    // stage 1: input

    std::cin >> temp_in >> unit_in;

    bool valid_unit = true;
    // we assume the user will input a valid unit

    // stage 2: data processing

    if(unit_in == "F" || unit_in == "f"){
        unit_out = "C";
        temp_out = F_to_C(temp_in);

    }
    else if(unit_in == "C" || unit_in == "c"){
        unit_out = "F";
        temp_out = C_to_F(temp_in);
    }
    else{
        valid_unit = false;
        // if the user inputs an invalid unit name
        // we update this variable
    }

    // stage 3: output 

    if(valid_unit){
        std::cout << temp_out << " " << unit_out << std::endl;
    }
    else{
        throw std::runtime_error("Error, unit not recognised");
    }

    return 0;

}