#include <iostream>
#include <vector>

int main() {
    // Take the number of elements as input
    int N;
    std::cin >> N;

    // Take a space-separated string of integers as input and convert them to a vector of integers
    std::vector<int> n(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> n[i];
    }

    // Initialize a counter to 1 and a position index to 0
    int a = 1;
    int pos = 0;

    // Loop through the array from the second element to the last
    for (int i = 1; i < N; ++i) {
        // Check if the current minimum element is greater than the current element
        if (n[pos] > n[i]) {
            // Increment the counter and update the position index
            a += 1;
            pos = i;
        }
    }

    // Print the final count of elements that are greater than the current minimum
    std::cout << a << std::endl;

    return 0;
}

// <END-OF-CODE>
