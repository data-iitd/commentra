#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> even, odd;

    // Count the occurrences of '0' and '1' at even indices
    for (size_t i = 0; i < s.size(); i += 2) {
        even[s[i]]++;
    }

    // Count the occurrences of '0' and '1' at odd indices
    for (size_t i = 1; i < s.size(); i += 2) {
        odd[s[i]]++;
    }

    // Calculate the minimum number of changes needed to make the string alternate
    // Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
    // Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
    // Print the minimum of the two options
    std::cout << std::min(s.size() - (even['0'] + odd['1']), s.size() - (even['1'] + odd['0'])) << std::endl;

    return 0;
}
