#include <iostream>
#include <vector>
#include <cstdlib> // for abs

int main() {
    // Ask the user for the number of elements in the list
    int n;
    std::cin >> n;

    // Initialize a vector to store the integers
    std::vector<int> l;

    // Iterate n times and append each integer to the vector
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        l.push_back(num);
    }

    // Initialize a variable to store the answer
    long long ans = n - 1;

    // Initialize a variable to store the previous integer in the list
    int last = 0;

    // Iterate through each integer in the vector
    for (int i = 0; i < n; i++) {
        // Calculate the absolute difference between the previous integer and the current integer
        // Add 1 to account for the number of steps between the two integers
        ans += std::abs(last - l[i]) + 1;

        // Update the value of the previous integer
        last = l[i];
    }

    // Print the value of the answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
