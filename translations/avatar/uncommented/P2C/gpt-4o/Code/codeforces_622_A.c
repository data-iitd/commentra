#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int l = 1;
    int r = n;
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        long long idxcnt = mid * (mid + 1) / 2; // Use long long to avoid overflow
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    l -= 1;
    long long idxcnt = l * (l + 1) / 2; // Use long long to avoid overflow
    printf("%d\n", n - idxcnt);
    
    return 0;
}

// <END-OF-CODE>
