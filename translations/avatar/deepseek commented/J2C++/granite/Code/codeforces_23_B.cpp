

#include <iostream> // Importing the iostream library for input/output operations

int maxLeft(int n) { // Defining the maxLeft function
    return n > 2? n - 2 : 0; // Returning n - 2 if n is greater than 2, otherwise returning 0
}

int main() { // The main function, the entry point of the program
    std::cin.tie(nullptr); // Disabling input stream synchronization
    std::ios::sync_with_stdio(false); // Disabling C++ stream buffer synchronization with C stream I/O
    int t; // Declaring the variable t to store the number of test cases
    std::cin >> t; // Reading the number of test cases
    while (t--) { // Looping through each test case
        int n; // Declaring the variable n to store the value of n for each test case
        std::cin >> n; // Reading the value of n for each test case
        std::cout << maxLeft(n) << "\n"; // Calling the maxLeft function and printing the result
    }
    return 0; // Returning 0 to indicate successful program execution
}

