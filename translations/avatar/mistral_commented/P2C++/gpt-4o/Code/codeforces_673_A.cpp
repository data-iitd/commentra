#include <iostream>
#include <vector>

int main() {
    // Take the number of elements in the list as input
    int n;
    std::cin >> n;

    // Initialize a vector 'arr' to store the input elements
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Check if the first element of the list is greater than 15
    if (arr[0] > 15) {
        // If it is, print 15
        std::cout << 15 << std::endl;
    } else {
        // Else, iterate through the list starting from the second element
        for (int i = 1; i < arr.size(); ++i) {
            // Check if the difference between the current and previous elements is greater than 15
            if (arr[i] - arr[i - 1] > 15) {
                // If it is, print the previous element plus 15
                std::cout << arr[i - 1] + 15 << std::endl;
                // Break the loop as we have found the answer
                break;
            }
            // Else, if we reach here, it means that no difference was greater than 15
            else if (i == arr.size() - 1) {
                // Check if the last element of the list is 90 or if adding 15 to it results in 90 or more
                if (arr[i] == 90 || arr[i] + 15 >= 90) {
                    // If it is, print 90
                    std::cout << 90 << std::endl;
                } else {
                    // Else, print the last element plus 15
                    std::cout << arr[i] + 15 << std::endl;
                }
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
