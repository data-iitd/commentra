#include <iostream> // Include iostream for input and output functions
#include <string>   // Include string for string manipulation functions

int main() {
    std::string c; // Declare string c
    std::string ans; // Declare string ans

    std::cin >> c; // Read input string into c

    // Process the input string
    for (char ch : c) {
        if (ch != 'B') {
            ans += ch; // Append character to ans if not 'B'
        } else if (!ans.empty()) {
            ans.pop_back(); // Remove last character from ans if 'B'
        }
    }

    std::cout << ans << std::endl; // Output the result string ans
}

// <END-OF-CODE>
