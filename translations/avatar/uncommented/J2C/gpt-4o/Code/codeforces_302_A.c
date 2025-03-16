#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            o++;
        } else {
            e++;
        }
    }
    
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int length = r - l + 1;
        
        if (length % 2 == 1) {
            printf("0\n");
        } else {
            if (length / 2 <= o && length / 2 <= e) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    
    return 0;
}

// <END-OF-CODE>
