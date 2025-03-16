// Include necessary headers
#include <iostream>
#include <vector>

// Create the Main class and define the main method
int main() {
    // Initialize a Scanner object to read input
    std::cin >> n >> a >> b; // Read the number of test cases, the number of elements in the first list, and the number of elements in the second list

    // Create ArrayList objects to store the lists
    std::vector<int> list1;
    std::vector<int> list2;

    // Read and store the elements of the first and second lists
    for (int i = 0; i < a; i++) {
        int x;
        std::cin >> x; // Read an element
        list1.push_back(x); // Add the element to list1
    }
    for (int i = 0; i < b; i++) {
        int x;
        std::cin >> x; // Read an element
        list2.push_back(x); // Add the element to list2
    }

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for (int i = 0; i < n; i++) {
        if (std::find(list1.begin(), list1.end(), i + 1) != list1.end()) { // Check if the current input element is present in list1
            std::cout << 1 << " "; // If present, print 1
        } else {
            std::cout << 2 << " "; // If not present, print 2
        }
    }

    // Close the Scanner object
    return 0;
}

