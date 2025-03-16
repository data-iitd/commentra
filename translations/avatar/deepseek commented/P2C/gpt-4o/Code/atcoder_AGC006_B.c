#include <stdio.h>
#include <stdlib.h>

void sub(int *y, int *len, int debug) {
    if (debug) {
        printf("D ");
        for (int i = 0; i < *len; i++) {
            printf("%d ", y[i]);
        }
        printf("\n");
    }
    
    while (*len > 1) {
        int new_len = *len - 2;
        int *new_y = (int *)malloc(new_len * sizeof(int));
        
        for (int i = 0; i < new_len; i++) {
            int triplet[3] = {y[i], y[i + 1], y[i + 2]};
            // Sort the triplet
            for (int j = 0; j < 3; j++) {
                for (int k = j + 1; k < 3; k++) {
                    if (triplet[j] > triplet[k]) {
                        int temp = triplet[j];
                        triplet[j] = triplet[k];
                        triplet[k] = temp;
                    }
                }
            }
            new_y[i] = triplet[1]; // Middle element
        }
        
        free(y);
        y = new_y;
        *len = new_len;
        
        if (debug) {
            printf("D ");
            for (int i = 0; i < *len; i++) {
                printf("%d ", y[i]);
            }
            printf("\n");
        }
    }
    
    free(y);
}

int calc(int *x, int len) {
    int *y = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        y[i] = x[i];
    }
    int y_len = len;
    
    sub(y, &y_len, 0);
    
    int result = y[0];
    if (result == 2) {
        sub(x, &len, 1);
        printf("= ");
        for (int i = 0; i < len; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    
    return result;
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
            xs = (int *)malloc((N - 1 + (N - 2)) * sizeof(int));
            for (int i = 0; i < N - 1; i++) {
                xs[i] = N - 1 + i;
            }
            for (int i = 0; i < N - 2; i++) {
                xs[N - 1 + i] = i + 1;
            }
        } else {
            xs = (int *)malloc((N - 3 + 4) * sizeof(int));
            int index = 0;
            for (int i = 1; i < X - 1; i++) {
                xs[index++] = i;
            }
            for (int i = X + 3; i < N * 2; i++) {
                xs[index++] = i;
            }
            xs[index++] = X + 2;
            xs[index++] = X - 1;
            xs[index++] = X;
            xs[index++] = X + 1;
        }
        
        for (int i = 0; i < (N - 3 + 4); i++) {
            printf("%d\n", xs[i]);
        }
        
        free(xs);
    }
    
    return 0;
}

// <END-OF-CODE>
