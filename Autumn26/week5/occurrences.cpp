#include <iostream> 
#include <vector>

std::vector<int> store_nums(int n) {
    std::vector<int> nums_list;

    for (int i = 0; i < n; i++) {
        int new_num;
        std::cout << "Please enter a number: " << std::endl;
        std::cin >> new_num;
        
        nums_list.push_back(new_num);
    }

    return nums_list;
}


int main() {
    std::cout << "Please enter n: ";
    int n;
    std::cin >> n;

    std::vector<int> nums_list = store_nums(n);

    std::cout << "Please enter s: " << std::endl;
    int s;
    std::cin >> s;

    int count = 0;
    for (int i = 0; i < nums_list.size(); i++) {
        if (nums_list[i] == s) {
            count += 1;
        }
    }

    std::cout << "The number of occurrences of s is " << count << std::endl;

    return 0;
}