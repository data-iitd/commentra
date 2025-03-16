#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
} TreeSet;

TreeSet* createTreeSet(int size) {
    TreeSet* set = (TreeSet*)malloc(sizeof(TreeSet));
    set->data = (int*)calloc(size, sizeof(int));
    set->size = 0;
    return set;
}

void addTreeSet(TreeSet* set, int value) {
    if (set->size == 0 || set->data[set->size - 1] < value) {
        set->data[set->size++] = value;
    } else {
        for (int i = 0; i < set->size; i++) {
            if (set->data[i] > value) {
                memmove(&set->data[i + 1], &set->data[i], (set->size - i) * sizeof(int));
                set->data[i] = value;
                set->size++;
                break;
            }
        }
    }
}

void removeTreeSet(TreeSet* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            memmove(&set->data[i], &set->data[i + 1], (set->size - i - 1) * sizeof(int));
            set->size--;
            break;
        }
    }
}

int findTreeSet(TreeSet* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, q;
    scanf("%d", &n);
    TreeSet* left = createTreeSet(n);
    int answer[n];
    memset(answer, 0, sizeof(answer));

    for (int i = 0; i < n; i++) {
        addTreeSet(left, i);
    }

    scanf("%d", &q);
    while (q--) {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        l--;
        r--;
        win--;
        while (left->size > 0) {
            int curr = left->data[0];
            if (curr < l || curr > r) {
                break;
            }
            answer[curr] = win;
            removeTreeSet(left, curr);
        }
        answer[win] = -1;
        addTreeSet(left, win);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(left->data);
    free(left);
    return 0;
}

