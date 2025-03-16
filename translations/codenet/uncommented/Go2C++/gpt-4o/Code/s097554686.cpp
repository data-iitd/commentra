#include <iostream>
#include <vector>

const int size = 100001;

int main() {
    int n, t;
    int l, r;
    std::vector<int> mem(size, 0);
    
    std::cin >> n;
    std::cin >> t;
    
    for (int i = 0; i < n; i++) {
        std::cin >> l;
        std::cin >> r;
        mem[l] += 1;
        mem[r] -= 1;
    }
    
    int ans = mem[0];
    for (int i = 1; i <= t; i++) {
        mem[i] += mem[i - 1];
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
