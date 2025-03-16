#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    // Initialize an empty vector 's' by taking input from the user
    std::string input;
    std::cin >> input;
    std::vector<char> s(input.begin(), input.end());

    // Create two unordered maps 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the vector 's' respectively
    std::unordered_map<char, int> even, odd;

    for (size_t i = 0; i < s.size() / 2; ++i) {
        even[s[i]]++;
    }
    for (size_t i = s.size() / 2; i < s.size(); ++i) {
        odd[s[i]]++;
    }

    // Calculate the minimum difference
    int min_diff = std::min(
        static_cast<int>(s.size()) - (even['0'] + odd['1']),
        static_cast<int>(s.size()) - (even['1'] + odd['0'])
    );

    // Print the result
    std::cout << min_diff << std::endl;

    return 0;
}
// <END-OF-CODE>
