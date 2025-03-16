#include <iostream>
#include <cstring>

int main() {
    char c[11], ans[11] = {'\0'};
    std::cin >> c;
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] != 'B') {
            ans[strlen(ans)] = c[i];
        } else {
            ans[strlen(ans) - 1] = '\0';
        }
    }
    std::cout << ans << std::endl;
}

// <END-OF-CODE>
