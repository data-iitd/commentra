#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string a;  // Declare a string to hold user input
    std::getline(std::cin, a);  // Take an input from the user

    std::vector<char> vo = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};  // Define a list of vowels

    // Iterate over the input string in reverse order
    for (int i = a.length() - 1; i >= 0; --i) {
        if (a[i] == ' ' || a[i] == '?') {  // Check if the current character is a space or a question mark
            continue;  // Continue to the next iteration
        } else {
            if (std::find(vo.begin(), vo.end(), a[i]) != vo.end()) {  // Check if the current character is a vowel
                std::cout << "YES" << std::endl;  // Print "YES" if the character is a vowel
            } else {
                std::cout << "NO" << std::endl;  // Print "NO" if the character is not a vowel
            }
            break;  // Break the loop after printing the result
        }
    }

    return 0;
}

// <END-OF-CODE>
