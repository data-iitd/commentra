#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string input;
    std::cin >> input;
    
    int sa = std::count(input.begin(), input.end(), '-');
    sa = std::min(n - sa, sa);
    
    std::vector<std::string> ss;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        b -= a;
        if (b % 2 && b <= sa * 2) {
            ss.push_back("1\n");
        } else {
            ss.push_back("0\n");
        }
    }
    
    std::cout << std::string(ss.begin(), ss.end());
    
    return 0;
}

// <END-OF-CODE>
