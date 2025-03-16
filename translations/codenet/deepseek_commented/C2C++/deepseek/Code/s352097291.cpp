#include <iostream> // Include iostream for input and output functions
#include <string>   // Include string for string manipulation functions

int main(){
    std::string c, ans = ""; // Declare string variables c and ans
    std::cin >> c; // Read input string into c

    // Process the input string
    for (int i = 0; i < c.length(); i++) {
        if (c[i] != 'B')
            ans += c[i]; // Append character to ans if not 'B'
        else if (ans.length() > 0)
            ans.pop_back(); // Remove last character from ans if 'B'
    }

    std::cout << ans << std::endl; // Output the result string ans
}
