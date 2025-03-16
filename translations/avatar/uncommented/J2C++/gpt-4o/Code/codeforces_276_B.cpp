#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    
    std::unordered_map<char, int> map;
    int oddCount = 0;

    for (char ch : str) {
        map[ch]++;
    }

    for (const auto& entry : map) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2 != 0) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
