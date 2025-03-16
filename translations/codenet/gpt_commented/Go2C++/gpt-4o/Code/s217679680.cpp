#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // Read an array of integers from standard input
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> arr;
    int num;

    // Split the input line into integers
    while (iss >> num) {
        arr.push_back(num);
    }

    // Assign the first two elements of the array to variables a and b
    int a = arr[0], b = arr[1];
    // Initialize the number of taps needed to 0
    int tap = 0;
    // Initialize the consent variable to 1 (the starting point)
    int consent = 1;

    // Loop until the consent value is less than b
    while (consent < b) {
        // Update consent by adding (a - 1) to it
        consent += a - 1;
        // Increment the tap count
        tap++;
    }

    // Print the total number of taps needed
    std::cout << tap << std::endl;

    return 0;
}

// <END-OF-CODE>
