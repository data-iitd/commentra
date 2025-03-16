
// Include necessary libraries
#include <iostream>
#include <vector>
#include <algorithm>

// Create the main function
int main() {
    // Initialize variables
    int n, a, b;
    std::cin >> n >> a >> b; // Read the number of test cases and the sizes of the lists

    // Create vectors to store the lists
    std::vector<int> list1(a);
    std::vector<int> list2(b);

    // Read and store the elements of the first and second lists
    for (int i = 0; i < a; i++) {
        std::cin >> list1[i]; // Read and store an element in list1
    }
    for (int i = 0; i < b; i++) {
        std::cin >> list2[i]; // Read and store an element in list2
    }

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for (int i = 0; i < n; i++) {
        if (std::find(list1.begin(), list1.end(), i + 1)!= list1.end()) { // Check if the current input element is present in list1
            std::cout << 1 << " "; // If present, print 1
        } else {
            std::cout << 2 << " "; // If not present, print 2
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}

