#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout) {
    for (int i = 0; i < vin.size(); i++) {
        if (vin[i] < t) {
            vout.push_back(vin[i]);
        }
    }
}

int main() {





    return 0;
}