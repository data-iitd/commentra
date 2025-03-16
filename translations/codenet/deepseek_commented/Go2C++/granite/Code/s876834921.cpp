
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s; // Step 1: Reading Input - The program starts by declaring a string variable `s` and using `std.cin` to read input from the user.

    s.replace(s.find("dream"), 5, "D"); // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
    s.replace(s.find("erase"), 5, "E");

    s.erase(std::remove(s.begin(), s.end(), 'D'), s.end()); // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
    s.erase(std::remove(s.begin(), s.end(), 'E'), s.end());
    s.erase(std::remove(s.begin(), s.end(), 'D'), s.end());
    s.erase(std::remove(s.begin(), s.end(), 'E'), s.end());

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return!std::isspace(ch);
    })); // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.

    if (s.empty()) { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
