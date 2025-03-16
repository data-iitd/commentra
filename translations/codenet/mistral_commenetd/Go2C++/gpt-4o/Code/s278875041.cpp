// Importing required headers
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Declaring a variable 'a' of type string
    std::string a;

    // Reading a string input from the user using std::cin
    std::cin >> a;

    // Declaring a temporary variable 'tmp' of type string
    std::string tmp = a;

    // Replacing all occurrences of '1' with '0' in the string 'a'
    std::replace(tmp.begin(), tmp.end(), '1', '0');

    // Replacing all occurrences of '9' with '1' in the string 'tmp'
    std::string b = tmp;
    std::replace(b.begin(), b.end(), '9', '1');

    // Replacing all occurrences of '0' with '9' in the string 'b'
    std::string ans = b;
    std::replace(ans.begin(), ans.end(), '0', '9');

    // Printing the final answer using std::cout
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
