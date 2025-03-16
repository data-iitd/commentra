#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    // Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
    int x = std::max(a.length(), b.length());
    a = std::string(x - a.length(), '0') + a;
    b = b + std::string(x - b.length(), '0');

    // Initializing an empty string 's' and a counter 'c' for carrying
    std::string s = "";
    int c = 0;

    // Iterating through each index 'i' in the range of the length of the padded strings 'x'
    for (int i = 0; i < x; ++i) {
        // Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
        int d = (b[x - i - 1] - '0') + (a[x - i - 1] - '0') + c;

        // If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
        if (d > 9) {
            s = std::to_string(d)[1] + s;
            c = 1;
        }
        // If the sum is less than or equal to 9, add the digit to the result string 's'
        else {
            s = std::to_string(d) + s;
            c = 0;
        }
    }

    // If there is still a carry left, add it to the result string 's'
    if (c == 1) {
        s = '1' + s;
    }

    // Printing the final result after removing the leading zeros (if any)
    std::cout << std::stoi(s) << std::endl;

    return 0;
}
