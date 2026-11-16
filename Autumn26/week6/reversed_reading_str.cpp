#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int main(){
    std::ifstream infile; 
    infile.open("bin/string_input.txt");

    std::vector<std::string> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmp;

    while(infile >> tmp){
        v.push_back(tmp);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i] << std::endl;
    }

    infile.close(); 

    // TODO: print the content of v in reversed order

}