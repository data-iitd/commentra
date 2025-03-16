#include <iostream>
#include <string>

int main() {
    const std::string LUCKY = "abcd";
    int n;
    std::cin >> n;
    std::string s = "";
    
    for (int i = 0; i < n; i++) {
        s += LUCKY[i % 4];
    }
    
    std::cout << s << std::endl;
    return 0;
}

// <END-OF-CODE>
