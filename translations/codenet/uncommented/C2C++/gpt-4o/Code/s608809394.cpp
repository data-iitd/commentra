#include <iostream>
#include <vector>

int main() {
    int n, m, s, t;
    std::cin >> n;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    t = 0;
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 1; j < n; j++) {
            if (j <= i) {
                continue;
            }
            m = a[i] * a[j];
            s = s + m;
        }
        t = t + s;
    }
    
    std::cout << t << std::endl;
    return 0;
}

// <END-OF-CODE>
