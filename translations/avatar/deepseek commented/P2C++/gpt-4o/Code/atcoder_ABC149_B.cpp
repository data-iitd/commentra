#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> cookies(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> cookies[i];  // Taking input from the user
    }

    int leftOver = cookies[0] - cookies[2];  // Calculating the difference between the first and third elements
    int takahashi = std::max(0, leftOver);  // Calculating the number of cookies Takahashi gets, ensuring it's not negative

    // Printing the result, including the number of cookies Takahashi gets and the number of cookies left for Aoki
    std::cout << takahashi << ' ' << (takahashi > 0 ? cookies[1] : std::max(0, cookies[1] - std::abs(leftOver))) << std::endl;

    return 0;
}

// <END-OF-CODE>
