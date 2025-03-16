
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int *q = (int *)malloc(sizeof(int) * N);
    int front = 0, rear = -1;
    for (int i = 0; i < N; i++) {
        q[++rear] = arr[i];
        while (front < rear && q[front] > q[front + 1]) {
            front++;
        }
        if (q[front] <= q[rear]) {
            sum++;
        }
    }
    return sum;
}

