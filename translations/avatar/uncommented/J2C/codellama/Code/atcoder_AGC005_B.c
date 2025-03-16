
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct {
    int *a;
    int *leftl;
    int *rightl;
    int N;
} Stack;

void init(Stack *s, int N) {
    s->a = (int *)malloc(N * sizeof(int));
    s->leftl = (int *)malloc(N * sizeof(int));
    s->rightl = (int *)malloc(N * sizeof(int));
    s->N = N;
}

void push(Stack *s, int index) {
    s->a[index] = index;
}

void pop(Stack *s, int index) {
    s->a[index] = -1;
}

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    int leftl[N];
    int rightl[N];
    Stack s;
    init(&s, N);
    int index = 0;
    while (index < N) {
        while (!s.a[s.N - 1] && a[s.N - 1] > a[index]) {
            int ind = s.N - 1;
            rightl[ind] = index - ind - 1;
            pop(&s, ind);
        }
        push(&s, index++);
    }
    while (!s.a[s.N - 1]) {
        int ind = s.N - 1;
        rightl[ind] = N - ind - 1;
        pop(&s, ind);
    }
    index = N - 1;
    while (index >= 0) {
        while (!s.a[s.N - 1] && a[s.N - 1] > a[index]) {
            int ind = s.N - 1;
            leftl[ind] = ind - index - 1;
            pop(&s, ind);
        }
        push(&s, index--);
    }
    while (!s.a[s.N - 1]) {
        int ind = s.N - 1;
        leftl[ind] = ind - index - 1;
        pop(&s, ind);
    }
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    printf("%ld\n", ans);
    return 0;
}

