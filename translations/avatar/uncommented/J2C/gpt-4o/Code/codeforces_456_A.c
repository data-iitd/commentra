#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n], b[n];
    int temp = 0, q = 0, w = 0, e = 0;
    bool f = false;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        
        if (temp < a[i]) {
            if (q > b[i]) {
                f = true;
            }
            q = b[i];
            temp = a[i];
        }
        if (temp > a[i]) {
            if (q < b[i]) {
                f = true;
            }
            q = b[i];
            temp = a[i];
        }
        if (a[i] > w) {
            w = a[i];
            if (b[i] < e) {
                f = true;
            }
            e = b[i];
        }
        if (a[i] < w) {
            if (b[i] > e) {
                f = true;
            }
        }
    }

    if (f == true) {
        printf("Happy Alex\n");
    } else {
        printf("Poor Alex\n");
    }

    return 0;
}

// <END-OF-CODE>
