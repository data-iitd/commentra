#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int count = 0;
    std::string target = "ABC";
    for (size_t i = 0; i <= s.length() - target.length(); ++i) {
        if (s.substr(i, target.length()) == target) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    return 0;
}

// <END-OF-CODE>
