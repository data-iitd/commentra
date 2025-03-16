#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} TreeSet;

TreeSet* createTreeSet(int capacity) {
    TreeSet* set = (TreeSet*)malloc(sizeof(TreeSet));
    set->array = (int*)malloc(capacity * sizeof(int));
    set->size = 0;
    set->capacity = capacity;
    return set;
}

void add(TreeSet* set, int value) {
    if (set->size < set->capacity) {
        set->array[set->size++] = value;
    }
}

void remove(TreeSet* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->array[i] == value) {
            set->array[i] = set->array[--set->size];
            break;
        }
    }
}

int contains(TreeSet* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->array[i] == value) {
            return 1;
        }
    }
    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    TreeSet* left = createTreeSet(n);
    int answer[n];
    memset(answer, -1, sizeof(answer));

    int q;
    scanf("%d", &q);

    while (q--) {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);

        for (int i = 0; i < left->size; i++) {
            if (left->array[i] >= l && left->array[i] <= r) {
                answer[left->array[i]] = win;
                remove(left, left->array[i]);
            }
        }

        answer[win - 1] = 0;
        add(left, win - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(left->array);
    free(left);

    return 0;
}

