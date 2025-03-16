#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Define a vector containing all the vowels in upper and lower case
    std::vector<char> vo = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };

    // Take an input string 'a' from the user
    std::string a;
    std::getline(std::cin, a);

    // Iterate through the string 'a' from the end to the beginning
    for (int i = a.length() - 1; i >= 0; i--) {
        // If the current character is a space or a question mark, skip it and move on to the next character
        if (a[i] == ' ' || a[i] == '?') {
            continue;
        }
        // If the current character is not a space or a question mark, check if it is a vowel or not
        else {
            // Check if the current character is a vowel
            if (std::find(vo.begin(), vo.end(), a[i]) != vo.end()) {
                // If it is, print "YES" and break out of the loop
                std::cout << "YES" << std::endl;
                break;
            }
            // If it is not, print "NO" and break out of the loop
            else {
                std::cout << "NO" << std::endl;
                break;
            }
        }
    }

    return 0;
}
