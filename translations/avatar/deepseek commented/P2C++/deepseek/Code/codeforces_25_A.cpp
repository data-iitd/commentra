#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate

int main() {
    int n;
    std::cin >> n;  // Take an integer input representing the number of elements

    std::vector<int> list;
    int x;
    while (std::cin >> x) {
        list.push_back(x % 2);  // Calculate remainders modulo 2 and add to the list
    }

    // Check if the sum of the list is 1
    if (std::accumulate(list.begin(), list.end(), 0) == 1) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i] == 1) {
                std::cout << i + 1 << std::endl;  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
                break;
            }
        }
    } else {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i] == 0) {
                std::cout << i + 1 << std::endl;  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
                break;
            }
        }
    }

    return 0;
}
