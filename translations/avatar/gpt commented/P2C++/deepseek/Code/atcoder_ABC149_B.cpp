#include <iostream>
#include <vector>
#include <algorithm> // for std::max

int main() {
    std::vector<int> cookies;
    int temp;

    // Read a line of input, split it into parts, and convert each part to an integer
    while (std::cin >> temp) {
        cookies.push_back(temp);
    }

    // Calculate the leftover cookies after taking some from the third type
    int leftOver = cookies[0] - cookies[2];

    // Determine the number of cookies Takahashi can take, ensuring it's not negative
    int takahashi = std::max(0, leftOver);

    // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
    // If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
    if (takahashi > 0) {
        std::cout << takahashi << ' ' << cookies[1];
    } else {
        std::cout << takahashi << ' ' << std::max(0, cookies[1] - abs(leftOver));
    }

    return 0;
}
