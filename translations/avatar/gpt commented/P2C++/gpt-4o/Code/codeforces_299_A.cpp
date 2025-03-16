#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the input from the first line
    std::string line;
    std::getline(std::cin, line);
    
    // Split the line into integers
    std::istringstream iss(line);
    std::vector<int> a;
    int num;
    while (iss >> num) {
        a.push_back(num);
    }

    // Sort the vector
    std::sort(a.begin(), a.end());

    // Check if any element in the vector 'a' is not divisible by the first element of 'a'
    bool not_divisible = false;
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] % a[0] != 0) {
            not_divisible = true;
            break;
        }
    }

    // Print the first element if all are divisible, otherwise print -1
    std::cout << (not_divisible ? -1 : a[0]) << std::endl;

    return 0;
}

// <END-OF-CODE>
