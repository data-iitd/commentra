#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::string s;
    std::cin >> s; // Read input string
    const int l = 2019; // Set the length variable

    // Initialize a vector to count occurrences of remainders, and variables for accumulated value and result
    std::vector<int> m(l, 0);
    m[0] = 1; // Initialize the count for remainder 0
    long long a = 0; // Accumulated value
    long long r = 0; // Result

    // Iterate over the input string in reverse order
    for (int i = 0; i < s.size(); ++i) {
        // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
        a += (s[s.size() - 1 - i] - '0') * static_cast<long long>(pow(10, i)) % l;

        // Update the result 'r' by adding the count of occurrences of the current remainder
        r += m[a % l];

        // Increment the count of the current remainder in the vector 'm'
        m[a % l]++;
    }

    // Print the final result
    std::cout << r << std::endl;

    return 0;
}

// <END-OF-CODE>
