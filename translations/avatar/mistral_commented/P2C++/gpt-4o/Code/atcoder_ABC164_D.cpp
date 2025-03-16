#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    // Define input variables 's' and 'l'
    std::string s;
    std::cin >> s;
    int l = 2019;

    // Initialize vector 'm' with initial value 1 for index 0 and zeros for other indices
    std::vector<int> m(l + 1, 0);
    m[0] = 1;

    // Initialize variables 'a' and 'r' with zero values
    long long a = 0, r = 0;

    // Iterate through the string 's' in reverse order
    for (int i = 0; i < s.size(); ++i) {
        char e = s[s.size() - 1 - i];
        // Calculate the current digit's power and add it to 'a'
        a += (e - '0') * static_cast<long long>(pow(10, i)) % l;

        // Increment the index 'a % l' in vector 'm'
        m[a % l]++;

        // Update 'r' with the current sum
        r += m[a % l];
    }

    // Print the final result 'r'
    std::cout << r << std::endl;

    return 0;
}

// <END-OF-CODE>
