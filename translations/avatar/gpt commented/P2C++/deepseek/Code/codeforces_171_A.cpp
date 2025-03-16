#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    // Determine the maximum length of the two strings
    int x = std::max(a.size(), b.size());

    // Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
    a = std::string(x - a.size(), '0') + a;
    b = b + std::string(x - b.size(), '0');

    // Initialize an empty string to store the result and a carry variable
    std::string s = "";
    int c = 0;

    // Iterate over each digit from the least significant to the most significant
    for (int i = x - 1; i >= 0; --i) {
        // Calculate the sum of the corresponding digits and the carry
        int d = (a[i] - '0') + (b[i] - '0') + c;

        // Check if the sum exceeds 9, which requires a carry
        if (d > 9) {
            s = std::string(1, d - 10 + '0') + s;  // Append the last digit of the sum to the result
            c = 1;  // Set carry to 1 for the next iteration
        } else {
            s = std::string(1, d + '0') + s;  // Append the sum to the result
            c = 0;  // Reset carry to 0
        }
    }

    // If there's a carry left after the last addition, append '1' to the result
    if (c == 1) {
        s = '1' + s;
    }

    // Print the final result, converting to int to remove leading zeros
    std::cout << std::stoi(s) << std::endl;

    return 0;
}
