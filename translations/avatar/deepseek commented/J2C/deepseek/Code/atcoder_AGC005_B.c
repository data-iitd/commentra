#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    
    int leftl[N], rightl[N];
    int* stack = (int*)malloc(N * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < N; ++i) {
        while (top >= 0 && a[stack[top]] > a[i]) {
            int ind = stack[top--];
            rightl[ind] = i - ind - 1;
        }
        stack[++top] = i;
    }
    while (top >= 0) {
        int ind = stack[top--];
        rightl[ind] = N - ind - 1;
    }
    
    for (int i = N - 1; i >= 0; --i) {
        while (top >= 0 && a[stack[top]] > a[i]) {
            int ind = stack[top--];
            leftl[ind] = ind - i - 1;
        }
        stack[++top] = i;
    }
    while (top >= 0) {
        int ind = stack[top--];
        leftl[ind] = ind - (N - 1) - 1;
    }
    
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    printf("%ld\n", ans);
    free(stack);
    return 0;
}
