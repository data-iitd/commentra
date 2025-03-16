
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* ArrayList_new(int capacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void ArrayList_add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = value;
}

int ArrayList_get(ArrayList *list, int index) {
    return list->data[index];
}

int ArrayList_size(ArrayList *list) {
    return list->size;
}

void ArrayList_delete(ArrayList *list) {
    free(list->data);
    free(list);
}

typedef struct {
    int n;
    int k;
    ArrayList **lists;
} Calculator;

Calculator* Calculator_new(int n, int k, ArrayList *as) {
    Calculator *calc = (Calculator*)malloc(sizeof(Calculator));
    calc->n = n;
    calc->k = k;
    calc->lists = (ArrayList**)malloc(sizeof(ArrayList*) * n);
    for (int i = 0; i < n; i++) {
        calc->lists[i] = ArrayList_new(n);
    }
    for (int i = 0; i < n; i++) {
        int j = ArrayList_get(as, i);
        if (i > 0) {
            ArrayList_add(calc->lists[j], i);
        } else if (j > 0) {
            calc->answer++;
        }
    }
    return calc;
}

int Calculator_calculate(Calculator *calc) {
    if (!calc->isCalculate) {
        calc->dfs(0, 0);
        calc->isCalculate = true;
    }
    return calc->answer;
}

int Calculator_dfs(Calculator *calc, int a, int pre) {
    int h = 0;
    for (int i = 0; i < ArrayList_size(calc->lists[a]); i++) {
        int b = ArrayList_get(calc->lists[a], i);
        h = fmax(h, Calculator_dfs(calc, b, a));
    }
    if (pre > 0 && h == calc->k - 1) {
        h = 0;
        calc->answer++;
    } else {
        h++;
    }
    return h;
}

int main() {
    int n, k;
    ArrayList *as = ArrayList_new(1000);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        ArrayList_add(as, a - 1);
    }
    Calculator *calc = Calculator_new(n, k, as);
    ArrayList_delete(as);
    printf("%d\n", Calculator_calculate(calc));
    for (int i = 0; i < n; i++) {
        ArrayList_delete(calc->lists[i]);
    }
    free(calc->lists);
    free(calc);
    return 0;
}

// 