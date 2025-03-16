#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i + 1 < n; i++) {
        std::sort(a.begin(), a.end());
        std::vector<double> na;
        for (int j = 2; j < a.size(); j++) {
            na.push_back(a[j]);
        }
        na.push_back((a[0] + a[1]) / 2);
        a = na;
    }
    
    std::cout << a[0] << std::endl;
    return 0;
}

// <END-OF-CODE>
