#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *a, *b, s, tem, q, i;
    while (scanf("%d", &n) != EOF) {
        a = (int*)malloc(n * sizeof(int));
        b = (int*)malloc(n * sizeof(int));
        s = -1;
        
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = 0;
        }
        
        tem = 1;
        q = 0;
        
        while (q != n) {
            s++;
            
            if (tem == 1) {
                for (i = 0; i < n; i++) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1;
                        q++;
                    }
                }
                tem = 0;
            } else {
                for (i = n - 1; i >= 0; i--) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1;
                        q++;
                    }
                }
                tem = 1;
            }
        }
        
        printf("%d\n", s);
        
        free(a);
        free(b);
    }
    return 0;
}

