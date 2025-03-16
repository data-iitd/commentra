#include <iostream>
#include <vector>

int main() {
    int n, cnt = 1;
    bool isup;
    bool issame = false;
    std::cin >> n;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    if (a[0] < a[1])
        isup = true;
    else if (a[0] > a[1])
        isup = false;
    else
        issame = true;

    for (int i = 1; i < n - 1; i++) {
        if (issame) {
            if (a[i] != a[i + 1]) {
                issame = false;
                if (a[i] < a[i + 1])
                    isup = true;
                else
                    isup = false;
            }
        } else {
            if (isup && a[i] <= a[i + 1]) {
                // do nothing
            } else if (!isup && a[i] >= a[i + 1]) {
                // do nothing
            } else {
                if (i + 2 < n) {
                    if (a[i + 1] < a[i + 2])
                        isup = true;
                    else if (a[i + 1] > a[i + 2])
                        isup = false;
                    else
                        issame = true;
                    cnt++;
                } else {
                    cnt++;
                    break;
                }
            }
        }
    }
    
    std::cout << cnt << std::endl;
    return 0;
}

// <END-OF-CODE>
