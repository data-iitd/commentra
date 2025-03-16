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
    int que[N];
    
    int front = 0, rear = 0;
    
    // Calculate the right counts for each element
    for (int index = 0; index < N; ++index) {
        while (front < rear && a[que[rear - 1]] > a[index]) {
            int ind = que[--rear];
            rightl[ind] = index - ind - 1;
        }
        que[rear++] = index;
    }
    
    while (front < rear) {
        int ind = que[--rear];
        rightl[ind] = N - ind - 1;
    }
    
    // Calculate the left counts for each element
    for (int index = N - 1; index >= 0; --index) {
        while (front < rear && a[que[rear - 1]] > a[index]) {
            int ind = que[--rear];
            leftl[ind] = ind - index - 1;
        }
        que[rear++] = index;
    }
    
    while (front < rear) {
        int ind = que[--rear];
        leftl[ind] = ind - index - 1;
    }
    
    // Calculate the final answer based on the left and right counts
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    // Output the final result
    printf("%ld\n", ans);
    
    return 0;
}
