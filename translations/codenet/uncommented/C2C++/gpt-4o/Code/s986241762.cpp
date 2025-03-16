#include <iostream>
#include <vector>

int main() {
    int n;
    long sum = 0;
    std::cin >> n;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            sum += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    
    std::cout << sum << std::endl;
}

// <END-OF-CODE>
