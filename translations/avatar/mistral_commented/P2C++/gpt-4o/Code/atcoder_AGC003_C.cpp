#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N; // Ask the user for an integer `N` and store it in a variable called `N`

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        int input;
        std::cin >> input; // Read an integer input by the user
        A[i] = input * N + i; // Create a list `A` with `N` elements
    }

    std::sort(A.begin(), A.end()); // Sort the list `A` in ascending order.

    int cnt = 0; // Initialize a counter `cnt` to zero.

    for (int i = 0; i < N; ++i) {
        int d = (A[i] % N) % 2; // Calculate the remainder of `A[i]` divided by `N` and modulo 2.

        if (d % 2 != i % 2) { // Check if the remainder of `d` divided by 2 is different from the remainder of `i` divided by 2.
            cnt++; // If they are different, increment the counter `cnt` by 1.
        }
    }

    std::cout << cnt / 2 << std::endl; // After the loop finishes, print the result of the counter `cnt` divided by 2.

    return 0;
} // <END-OF-CODE>
