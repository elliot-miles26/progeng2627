#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin) {
    int min = vin[0];

    if (vin.size() == 0) {
        return -1;
    }

    for (int i = 0; i < vin.size(); i++) {
        if (vin[i] < i)  {
            min = vin[i];
        }
    }

    return min;
}

int main() {
    std::vector<double> vin;

    std::cout << "Please enter n: ";
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int new_num;
        std::cout << "Please enter a number: " << std::endl;
        std::cin >> new_num;
        
        vin.push_back(new_num);
    }

    int min = min_vector_element(vin);
    std::cout << "Min value: " << min << std::endl;


    return 0;
}