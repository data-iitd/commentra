#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    int tmpSum = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
        tmpSum += l[i];
        if (tmpSum <= x) {
            rs = i + 1; // i + 1 because we want the count of elements
        } else {
            break;
        }
    }
    
    printf("%d\n", rs);
    return 0;
}

// <END-OF-CODE>
