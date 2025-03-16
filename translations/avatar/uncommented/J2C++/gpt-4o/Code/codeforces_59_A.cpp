#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string word;
    std::cin >> word;
    
    int uppercase = 0;
    int lowercase = 0;

    for (char ch : word) {
        if (std::isupper(ch)) {
            uppercase++;
        } else {
            lowercase++;
        }
    }

    if (uppercase > lowercase) {
        std::cout << std::string(word.begin(), word.end()).append(1, '\0') << std::endl; // Convert to uppercase
    } else {
        std::cout << std::string(word.begin(), word.end()).append(1, '\0') << std::endl; // Convert to lowercase
    }

    return 0;
}

// <END-OF-CODE>
