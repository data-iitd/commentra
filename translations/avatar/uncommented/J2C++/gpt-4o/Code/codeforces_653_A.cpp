#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::set<int> unique_values;
    
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        unique_values.insert(value);
    }
    
    std::vector<int> a(unique_values.begin(), unique_values.end());
    bool found = false;
    
    for (size_t i = 0; i < a.size(); i++) {
        if (i + 2 < a.size()) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = true;
                break;
            }
        }
    }
    
    std::cout << (found ? "YES" : "NO") << std::endl;
    return 0;
}

// <END-OF-CODE>
