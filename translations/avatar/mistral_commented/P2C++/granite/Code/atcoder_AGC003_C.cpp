
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    // Ask the user for an integer `N` and store it in a variable called `N`

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        // Ask the user for an integer `a` and store it in the `i`-th element of the vector `A`.
        A[i] = a * N + i;
    }

    std::sort(A.begin(), A.end());
    // Sort the vector `A` in ascending order.

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        // Calculate the remainder of `A[i]` divided by `N` and modulo 2.
        // Store this result in a variable called `d`.

        if (d % 2!= i % 2) {
            // Check if the remainder of `d` divided by 2 is different from the remainder of `i` divided by 2.
            // If they are different, increment the counter `cnt` by 1.
            cnt++;
        }
    }

    std::cout << cnt / 2 << std::endl;
    // After the loop finishes, print the result of the counter `cnt` divided by 2.

    return 0;
}
