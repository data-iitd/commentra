#include <iostream>
#include <vector>
#define N 2000

int main() {
    int num1, num2, ans, sum = 0;
    std::vector<int> math(N + 1, 0); // Initialize math array with 0s
    math[0] = 1; // Set the first element as 1

    // Read the number of integers to be input
    std::cout << "Enter the number of integers to be input:\n";
    std::cin >> num1;

    // Read each integer and calculate its sum
    for (int i = 0; i < num1; i++) {
        int a;
        std::cout << "Enter an integer:\n";
        std::cin >> a;

        // Add the current integer to the sum
        sum += a;

        // Mark all the previous numbers as visited
        for (int j = sum - a; j >= 0; j--) {
            if (math[j] == 1) math[j + a] = 1;
        }
    }

    // Read the number of integers to be checked
    std::cout << "Enter the number of integers to be checked:\n";
    std::cin >> num2;

    // Check each integer and print the result
    for (int i = 0; i < num2; i++) {
        std::cout << "Enter an integer to check:\n";
        std::cin >> ans;

        // Check if the current integer is marked as visited
        if (math[ans] == 1) std::cout << "yes\n";
        else std::cout << "no\n";
    }

    return 0; // Indicate successful execution
}

// <END-OF-CODE>
