#include <iostream>

int main() {
    int n;
    std::cin >> n;  // Read the integer n from standard input.

    int cnt4 = 0, cnt2 = 0;  // Initialize counters for multiples of 4 and multiples of 2.

    // Read n integers from standard input and update the counters.
    for (int i = 0; i < n; i++) {
        int wk;
        std::cin >> wk;
        if (wk % 4 == 0)  // Check if the integer is a multiple of 4.
            cnt4++;
        else if (wk % 2 == 0)  // Check if the integer is a multiple of 2 but not 4.
            cnt2++;
    }

    // Check if the sum of multiples of 4 and multiples of 2 (divided by 2) is greater than or equal to n/2.
    if (cnt4 + cnt2 / 2 >= n / 2)
        std::cout << "Yes\n";  // Print "Yes" if the condition is met.
    else
        std::cout << "No\n";  // Print "No" otherwise.

    return 0;
}

// <END-OF-CODE>
