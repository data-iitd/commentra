#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define a vector 'cookies' by reading input
    std::vector<int> cookies(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> cookies[i];
    }

    // Calculate the difference between the number of cookies given to the first and second child
    int leftOver = cookies[0] - cookies[2];

    // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
    int takahashi = std::max(0, leftOver);

    // Print the result using string concatenation
    std::cout << takahashi << ' ' <<
        (takahashi > 0 ? cookies[1] : std::max(0, cookies[1] - std::abs(leftOver))) << std::endl;

    return 0;
}

// <END-OF-CODE>
