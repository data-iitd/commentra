#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    // Read input string
    std::string s;
    std::cin >> s;

    // Count the occurrences of '0' and '1' at even and odd indices
    std::unordered_map<char, int> even, odd;

    for (size_t i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            even[s[i]]++;
        } else {
            odd[s[i]]++;
        }
    }

    // Calculate the minimum number of changes needed to make the string alternate
    // Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
    // Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
    int option1 = s.size() - (even['0'] + odd['1']);
    int option2 = s.size() - (even['1'] + odd['0']);

    // Print the minimum of the two options
    std::cout << std::min(option1, option2) << std::endl;

    return 0;
}

// <END-OF-CODE>
