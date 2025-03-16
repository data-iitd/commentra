#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    int leftl[N], rightl[N];
    int index = 0;

    // Reading the elements of the array from the console and storing them in the array
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    int que[N];
    int front = 0, rear = 0;

    // Finding the length of the left and right segments for each element using two stacks
    while (index < N) {
        while (front < rear && a[que[rear - 1]] > a[index]) {
            int ind = que[--rear];
            rightl[ind] = index - ind - 1;
        }
        que[rear++] = index++;
    }

    // Calculating the length of the right segment for the last element
    while (front < rear) {
        int ind = que[--rear];
        rightl[ind] = N - ind - 1;
    }

    index = N - 1;

    // Finding the length of the left segments for each element using two stacks in reverse order
    while (index >= 0) {
        while (front < rear && a[que[rear - 1]] > a[index]) {
            int ind = que[--rear];
            leftl[ind] = ind - index - 1;
        }
        que[rear++] = index--;
    }

    // Calculating the length of the left segment for the first element
    while (front < rear) {
        int ind = que[--rear];
        leftl[ind] = ind - index - 1;
    }

    long ans = 0;

    // Calculating the answer by multiplying the element, left segment length, and right segment length for each element
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    // Printing the final answer
    printf("%ld\n", ans);
    return 0;
}

