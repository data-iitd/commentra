#include <iostream>
#include <vector>
#include <cstdlib> // for abs function

int main() {
    // Read the number of elements from user input
    int n;
    std::cin >> n;

    // Initialize a vector to store the elements
    std::vector<int> l;

    // Loop to read 'n' integers from user input and append them to the vector
    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        l.push_back(element);
    }

    // Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
    long long ans = n - 1;

    // Initialize a variable to keep track of the last element processed
    int last = 0;

    // Loop through each element in the vector
    for (int i = 0; i < n; i++) {
        // Calculate the distance from the last element to the current element
        // and add 1 for the step to the current element
        ans += std::abs(last - l[i]) + 1;

        // Update 'last' to the current element for the next iteration
        last = l[i];
    }

    // Print the final calculated answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
