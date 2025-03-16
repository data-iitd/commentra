#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
} Stack;

void initStack(Stack *s) {
    s->data = (char *)malloc(1000001 * sizeof(char));
    s->top = -1;
}

void push(Stack *s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

int main() {
    char x[1000001];
    Stack s;
    int c = 0;

    scanf("%s", x);
    initStack(&s);

    for (int i = 0; i < strlen(x); i++) {
        push(&s, x[i]);

        while (s.top > 0) {
            char p = pop(&s);
            char q = pop(&s);

            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            }

            push(&s, q);
            push(&s, p);
            break;
        }
    }

    printf("%d\n", c * 2);
    free(s.data);
    return 0;
}

