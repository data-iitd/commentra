#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_V 100001
#define MOD 1000000007
typedef struct {
    int *data;
    int size;
} Vector;

Vector *vector_create(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
    return v;
}

void vector_free(Vector *v) {
    free(v->data);
    free(v);
}

int vector_get(Vector *v, int index) {
    return v->data[index];
}

void vector_set(Vector *v, int index, int value) {
    v->data[index] = value;
}

int vector_size(Vector *v) {
    return v->size;
}

int *vector_data(Vector *v) {
    return v->data;
}

int main() {
    int n;
    scanf("%d", &n);
    Vector *ans = vector_create(n);
    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        a--;
        vector_set(ans, a, vector_get(ans, a) + 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", vector_get(ans, i));
    }
    vector_free(ans);
    return 0;
}

