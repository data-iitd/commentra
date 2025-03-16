#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} ArrayList;

ArrayList* createArrayList() {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->array = (int*)malloc(10 * sizeof(int));
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addElement(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}

void freeArrayList(ArrayList *list) {
    free(list->array);
    free(list);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, q, l, r, win;
    scanf("%d", &n);
    ArrayList *left = createArrayList();
    int answer[n];
    memset(answer, 0, sizeof(answer));
    for (int i = 0; i < n; i++) {
        addElement(left, i);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &l, &r, &win);
        l--;
        r--;
        win--;
        int *curr;
        while ((curr = bsearch(&l, left->array, left->size, sizeof(int), compare)) != NULL && *curr <= r) {
            int index = curr - left->array;
            answer[index] = win;
            left->array = (int*)realloc(left->array, (left->size - 1) * sizeof(int));
            left->size--;
        }
        answer[win] = 0;
        addElement(left, win);
    }
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
    }
    printf("\n");
    freeArrayList(left);
    return 0;
}
