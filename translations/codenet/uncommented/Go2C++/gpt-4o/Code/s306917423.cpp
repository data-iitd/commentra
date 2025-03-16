#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (char c : s) {
        if (c == '1') {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
