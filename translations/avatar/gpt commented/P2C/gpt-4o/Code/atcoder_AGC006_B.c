#include <stdio.h>
#include <stdlib.h>

void sub(int *y, int *len, int debug) {
    if (debug) {
        for (int i = 0; i < *len; i++) {
            printf("%d ", y[i]);
        }
        printf("\n");
    }
    
    while (*len > 1) {
        int new_len = *len - 2;
        int *new_y = (int *)malloc(new_len * sizeof(int));
        
        for (int i = 0; i < new_len; i++) {
            int a = y[i];
            int b = y[i + 1];
            int c = y[i + 2];
            // Find the second largest of a, b, c
            if ((a >= b && a <= c) || (a <= b && a >= c)) {
                new_y[i] = a;
            } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
                new_y[i] = b;
            } else {
                new_y[i] = c;
            }
        }
        
        free(y);
        y = new_y;
        *len = new_len;
        
        if (debug) {
            for (int i = 0; i < *len; i++) {
                printf("%d ", y[i]);
            }
            printf("\n");
        }
    }
    
    free(y);
}

int calc(int *x, int len) {
    sub(x, &len, 0);
    return x[0];
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    if (X == 1 || X == N * 2 - 1) {
        printf("No\n");
    } else {
        printf("Yes\n");
        
        int *xs;
        if (X == N * 2 - 2) {
            xs = (int *)malloc((N + 1) * sizeof(int));
            int index = 0;
            for (int i = N - 1; i <= X + 1; i++) {
                xs[index++] = i;
            }
            for (int i = 1; i < N - 1; i++) {
                xs[index++] = i;
            }
        } else {
            int *ys = (int *)malloc((N * 2) * sizeof(int));
            int index = 0;
            for (int i = 1; i < X - 1; i++) {
                ys[index++] = i;
            }
            for (int i = X + 3; i < N * 2; i++) {
                ys[index++] = i;
            }
            xs = (int *)malloc((N - 3 + 4) * sizeof(int));
            for (int i = 0; i < N - 3; i++) {
                xs[i] = ys[i];
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            xs[N] = X + 1;
            for (int i = N - 3; i < index; i++) {
                xs[N + 1 + i - (N - 3)] = ys[i];
            }
            free(ys);
        }
        
        for (int i = 0; i < N + 1; i++) {
            printf("%d\n", xs[i]);
        }
        
        free(xs);
    }
    
    return 0;
}

// <END-OF-CODE>
