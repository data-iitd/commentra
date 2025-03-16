#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::string s;
    int l = 2019;
    std::cin >> s; // Take input string `s`
    
    std::vector<int> m(2020, 0); // Initialize vector `m` with a length of 2020 (1 extra for the 1 at the beginning)
    m[0] = 1; // Prepend a 1 at the beginning
    int a = 0, r = 0;

    for (int i = 0; i < s.size(); ++i) {
        char e = s[s.size() - 1 - i]; // Iterate over the reversed string `s`
        a += (e - '0') * static_cast<int>(pow(10, i)) % l; // Calculate the value of the character's position
        r += m[a % l]; // Increment the running total `r`
        m[a % l]++; // Increment the value in `m` at the position `a % l`
    }

    std::cout << r << std::endl; // Finally, print the value of `r`
    return 0;
}
// <END-OF-CODE>
