#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

int main() {
    int N;
    scanf("%d", &N);
    int a[MAX_SIZE];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    int leftl[MAX_SIZE];
    int rightl[MAX_SIZE];
    int index = 0;
    int que[MAX_SIZE];
    int front = -1;
    int rear = -1;
    while (index < N) {
        while (front != -1 && a[que[front]] > a[index]) {
            int ind = que[front];
            rightl[ind] = index - ind - 1;
            front = (front + 1) % MAX_SIZE;
        }
        que[++rear % MAX_SIZE] = index++;
    }
    while (front != -1) {
        int ind = que[front];
        rightl[ind] = N - ind - 1;
        front = (front + 1) % MAX_SIZE;
    }
    index = N - 1;
    while (index >= 0) {
        while (front != -1 && a[que[front]] > a[index]) {
            int ind = que[front];
            leftl[ind] = ind - index - 1;
            front = (front + 1) % MAX_SIZE;
        }
        que[++rear % MAX_SIZE] = index--;
    }
    while (front != -1) {
        int ind = que[front];
        leftl[ind] = ind - index - 1;
        front = (front + 1) % MAX_SIZE;
    }
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    printf("%ld\n", ans);
    return 0;
}

