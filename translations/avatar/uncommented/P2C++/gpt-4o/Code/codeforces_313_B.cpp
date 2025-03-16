#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string soz;
    std::cin >> soz;
    
    std::vector<int> a(soz.length() + 1, 0);
    
    for (size_t i = 1; i < soz.length(); ++i) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }
    
    int n;
    std::cin >> n;
    std::vector<int> arr;
    
    for (int i = 0; i < n; ++i) {
        int m, l;
        std::cin >> m >> l;
        arr.push_back(a[l - 1] - a[m - 1]);
    }
    
    for (const auto& value : arr) {
        std::cout << value << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
