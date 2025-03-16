#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1000000
#define MAX_M 1000000
#define MAX_K 1000000

typedef struct {
    int *data;
    int size;
} Array;

typedef struct {
    int *data;
    int size;
} Map;

Array *new_array(int size) {
    Array *array = (Array *)malloc(sizeof(Array));
    array->data = (int *)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

Map *new_map(int size) {
    Map *map = (Map *)malloc(sizeof(Map));
    map->data = (int *)malloc(sizeof(int) * size);
    map->size = size;
    return map;
}

void free_array(Array *array) {
    free(array->data);
    free(array);
}

void free_map(Map *map) {
    free(map->data);
    free(map);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

Map *prime_factorize(int n) {
    Map *res = new_map(MAX_N);
    for (int i = 2; i*i <= n; i++) {
        for (; n % i == 0; n /= i) {
            res->data[i]++;
        }
    }
    if (n != 1) {
        res->data[n]++;
    }
    return res;
}

int pow(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k-1) * n % MAX_N;
    } else {
        int t = pow(n, k/2);
        return t * t % MAX_N;
    }
}

int add(int a, int b) {
    return (a + b) % MAX_N;
}

int sub(int a, int b) {
    return (a + MAX_N - b) % MAX_N;
}

int mul(int a, int b) {
    return a % MAX_N * b % MAX_N % MAX_N;
}

int div(int a, int b) {
    return mul(a, pow(b, MAX_N-2));
}

int main() {
    int n;
    scanf("%d", &n);
    Array *as = new_array(n);
    Map *ps = new_map(MAX_N);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as->data[i]);

        Map *ns = prime_factorize(as->data[i]);
        for (int k = 0; k < ns->size; k++) {
            ps->data[k] = max(ps->data[k], ns->data[k]);
        }
    }

    int x = 1;
    for (int k = 0; k < ps->size; k++) {
        for (int i = 1; i <= ps->data[k]; i++) {
            x = mul(x, k);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, as->data[i]));
    }
    printf("%d\n", ans);

    free_array(as);
    free_map(ps);
    return 0;
}

