#include <iostream>
#include <vector>
#include <cstring>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> r0(n, false);
    std::vector<int> r1;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a > b) {
            std::swap(a, b);
        }
        if (a == 1) r0[b - 1] = true;
        if (b == n) r1.push_back(a - 1);
    }
    
    bool res = false;
    for (int i = 0; i < r1.size(); i++) {
        if (r0[r1[i]]) res = true;
    }
    
    std::cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
    return 0;
}

// <END-OF-CODE>
