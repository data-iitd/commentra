
#include <iostream>
#include <string>

int main() {
    std::string a;
    std::cin >> a;

    std::string vo = "aeiouyAEIOUY";

    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] =='' || a[i] == '?') {
            continue;
        } else {
            if (vo.find(a[i])!= std::string::npos) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
            break;
        }
    }

    return 0;
}
