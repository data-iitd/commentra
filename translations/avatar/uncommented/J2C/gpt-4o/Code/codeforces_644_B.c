#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *data;
    int front;
    int rear;
    int size;
    int capacity;
} LinkedList;

LinkedList* createLinkedList(int capacity) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->capacity = capacity;
    list->front = 0;
    list->rear = -1;
    list->size = 0;
    list->data = (long*)malloc(capacity * sizeof(long));
    return list;
}

void freeLinkedList(LinkedList* list) {
    free(list->data);
    free(list);
}

void add(LinkedList* list, long value) {
    if (list->size < list->capacity) {
        list->rear = (list->rear + 1) % list->capacity;
        list->data[list->rear] = value;
        list->size++;
    }
}

void pollFirst(LinkedList* list) {
    if (list->size > 0) {
        list->front = (list->front + 1) % list->capacity;
        list->size--;
    }
}

long getFirst(LinkedList* list) {
    if (list->size > 0) {
        return list->data[list->front];
    }
    return -1; // or some sentinel value
}

long getLast(LinkedList* list) {
    if (list->size > 0) {
        return list->data[list->rear];
    }
    return -1; // or some sentinel value
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    long *ans = (long*)malloc(n * sizeof(long));
    LinkedList* q = createLinkedList(b + 1); // +1 to handle the case when size is equal to b

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        
        while (q->size > 0 && getFirst(q) <= t) {
            pollFirst(q);
        }
        
        if (q->size <= b) {
            ans[i] = (q->size == 0 ? t : getLast(q)) + d;
            add(q, ans[i]);
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%ld ", ans[i]);
    }

    free(ans);
    freeLinkedList(q);
    return 0;
}
