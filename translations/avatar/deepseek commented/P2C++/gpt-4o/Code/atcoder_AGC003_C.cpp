#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // The code reads an integer N.
    int N;
    std::cin >> N;

    // It then creates a list A where each element is the product of an integer input and N plus its index i, for i in range(N).
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        int input;
        std::cin >> input;
        A[i] = input * N + i;
    }

    // The list A is sorted.
    std::sort(A.begin(), A.end());

    // A counter cnt is initialized to 0.
    int cnt = 0;

    // The code then iterates over the elements of A, checking if the remainder when divided by N, when divided by 2, matches the remainder of the index i when divided by 2.
    for (int i = 0; i < N; ++i) {
        int d = (A[i] % N) % 2;
        if (d % 2 != i % 2) {
            cnt++;
        }
    }

    // Finally, the code prints the result of cnt divided by 2.
    std::cout << cnt / 2 << std::endl;

    return 0;
}

// <END-OF-CODE>
