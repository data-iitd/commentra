#include <iostream>
#include <string>

int main() {
    std::string a;
    std::cin >> a;
    std::string ans = "Good";
    
    for (int i = 0; i < 3; i++) {
        if (a[i] == a[i + 1]) {
            ans = "Bad";
            break; // Exit the loop early if "Bad" is determined
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
