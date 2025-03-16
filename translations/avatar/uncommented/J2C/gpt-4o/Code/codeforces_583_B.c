#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[n];
        int b[n];
        int s = -1;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = 0;
        }
        
        int tem = 1;
        int q = 0;
        
        while (q != n) {
            s++;
            if (tem == 1) {
                for (int i = 0; i < n; i++) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1;
                        q++;
                    }
                }
                tem = 0;
            } else {
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1;
                        q++;
                    }
                }
                tem = 1;
            }
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}

// <END-OF-CODE>
