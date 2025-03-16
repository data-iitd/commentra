
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
    // Read input string and set the length variable
    std::string s;
    int l = 2019;
    std::cin >> s;

    // Initialize a vector to count occurrences of remainders, and variables for accumulated value and result
    std::vector<int> m(l, 1);
    int a = 0, r = 0;

    // Iterate over the input string in reverse order
    for (int i = s.size() - 1; i >= 0; i--) {
        // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
        a = (a + (s[i] - '0') * pow(10, s.size() - i - 1)) % l;

        // Update the result 'r' by adding the count of occurrences of the current remainder
        r += m[a];

        // Increment the count of the current remainder in the vector'm'
        m[a]++;
    }

    // Print the final result
    std::cout << r << std::endl;

    return 0;
}
