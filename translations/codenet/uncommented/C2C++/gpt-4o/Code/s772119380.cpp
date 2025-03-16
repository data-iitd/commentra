#include <iostream>
#include <vector>

int main() {
    std::vector<int> a(1000);
    int n, d = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++) {   
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                d++;
            }
        }
    }

    std::cout << a[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << a[i];
    }
    std::cout << "\n" << d << "\n";
    return 0;
}

// <END-OF-CODE>
