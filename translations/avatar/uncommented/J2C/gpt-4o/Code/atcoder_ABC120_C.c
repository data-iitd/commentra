#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

typedef struct {
    char *data;
    int top;
} Stack;

void initStack(Stack *s, int size) {
    s->data = (char *)malloc(size * sizeof(char));
    s->top = -1;
}

void push(Stack *s, char value) {
    s->data[++(s->top)] = value;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

int size(Stack *s) {
    return s->top + 1;
}

void freeStack(Stack *s) {
    free(s->data);
}

int main() {
    char x[MAX_LENGTH];
    scanf("%s", x);
    
    Stack s;
    initStack(&s, MAX_LENGTH);
    
    int c = 0;
    for (int i = 0; i < strlen(x); i++) {
        push(&s, x[i]);
        while (size(&s) > 1) {
            char p = pop(&s);
            char q = pop(&s);
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            } else {
                push(&s, q);
                push(&s, p);
                break;
            }
        }
    }
    
    printf("%d\n", c * 2);
    
    freeStack(&s);
    return 0;
}

// <END-OF-CODE>
