#include <iostream>
#include <string>
#include <vector>

int main() {
    // Take input from the user
    std::string a;
    std::getline(std::cin, a);

    // Define a list of vowels (both lowercase and uppercase)
    std::vector<char> vo = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

    // Iterate through the input string in reverse order
    for (int i = a.length() - 1; i >= 0; --i) {
        // Check if the current character is a space or a question mark
        if (a[i] == ' ' || a[i] == '?') {
            continue;  // Skip to the next iteration if it is a space or '?'
        } else {
            // Check if the current character is a vowel
            if (std::find(vo.begin(), vo.end(), a[i]) != vo.end()) {
                std::cout << "YES" << std::endl;  // Print "YES" if it is a vowel
            } else {
                std::cout << "NO" << std::endl;   // Print "NO" if it is not a vowel
            }
            break;  // Exit the loop after processing the first non-space character
        }
    }

    return 0;
}

// <END-OF-CODE>
