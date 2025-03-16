
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct Element *next;
} Element;

typedef struct {
    Element *top;
    int size;
} Stack;

Stack *newStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, int value) {
    Element *e = (Element *)malloc(sizeof(Element));
    e->value = value;
    e->next = s->top;
    s->top = e;
    s->size++;
}

int pop(Stack *s) {
    if (s->size == 0) {
        return -1;
    }
    Element *e = s->top;
    s->top = e->next;
    s->size--;
    int value = e->value;
    free(e);
    return value;
}

int len(Stack *s) {
    return s->size;
}

int main() {
    Stack *s = newStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", len(s));
    return 0;
}
