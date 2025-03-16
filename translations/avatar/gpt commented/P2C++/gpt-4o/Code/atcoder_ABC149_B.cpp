#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read a line of input, split it into parts, and convert each part to an integer
    std::vector<int> cookies(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> cookies[i];
    }

    // Calculate the leftover cookies after taking some from the third type
    int leftOver = cookies[0] - cookies[2];

    // Determine the number of cookies Takahashi can take, ensuring it's not negative
    int takahashi = std::max(0, leftOver);

    // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
    // If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
    std::cout << takahashi << ' ' << (takahashi > 0 ? cookies[1] : std::max(0, cookies[1] - std::abs(leftOver))) << std::endl;

    return 0;
}

// <END-OF-CODE>
