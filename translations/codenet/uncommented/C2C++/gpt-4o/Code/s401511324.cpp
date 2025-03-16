#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, cnt = 0;
    std::cin >> n;
    std::vector<int> l(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
    }
    
    // Sort the array
    std::sort(l.begin(), l.end());
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (l[i] + l[j] > l[k]) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
    }
    
    std::cout << cnt << std::endl;
    return 0;
}

// <END-OF-CODE>
