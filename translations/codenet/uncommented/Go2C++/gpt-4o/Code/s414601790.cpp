#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int max = 0;
    int cnt = 0;
    for (char r : s) {
        if (r == 'I') {
            cnt++;
        } else {
            cnt--;
        }

        if (cnt > max) {
            max = cnt;
        }
    }

    std::cout << max << std::endl;
    return 0;
}

// <END-OF-CODE>
