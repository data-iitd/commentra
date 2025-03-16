#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)malloc(size * sizeof(char));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, char c) {
    stack->data[++stack->top] = c;
}

char pop(Stack* stack) {
    return stack->data[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int main() {
    char x[100001];
    scanf("%s", x);
    int len = strlen(x);
    Stack* s = createStack(len);
    int c = 0;

    for (int i = 0; i < len; i++) {
        push(s, x[i]);
        while (!isEmpty(s) && s->top > 0) {
            char p = pop(s);
            char q = pop(s);
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            } else {
                push(s, q);
                push(s, p);
                break;
            }
        }
    }

    printf("%d\n", c * 2);
    free(s->data);
    free(s);
    return 0;
}
