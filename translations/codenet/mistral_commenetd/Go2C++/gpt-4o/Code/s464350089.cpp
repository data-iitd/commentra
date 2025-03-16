// Constants and package imports
#include <iostream>
#include <vector>

const int mod = 1000000007;

int main() {
    // Reading the first two integers h and n
    int h, n;
    std::cin >> h >> n;

    // Initializing variable a to 0
    int a = 0;

    // Iterating through the array of size n and adding each integer to variable a
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a += x;
    }

    // Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    if (h > a) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
