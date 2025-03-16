#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::string input;
    std::getline(std::cin, input); // Read the rest of the line to get the '-' count
    int sa = input.count('-');
    
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
    
    for (const auto& s : ss) {
        std::cout << s;
    }
    
    return 0;
}

