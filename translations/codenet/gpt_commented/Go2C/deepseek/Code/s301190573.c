#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

char buffer[SIZE];
int par[100000], rank[100000];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int root(int i) {
    if (par[i] == i) {
        return i;
    }
    return par[i] = root(par[i]);
}

int same(int i, int j) {
    return root(i) == root(j);
}

void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
    }
}

void read_line(char *line, int size) {
    fgets(line, size, stdin);
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
}

int read_int() {
    int x;
    scanf("%d", &x);
    getchar(); // Consume newline
    return x;
}

int read_ints() {
    int x, y;
    scanf("%d %d", &x, &y);
    getchar(); // Consume newline
    return x, y;
}

int* read_int_array(int *n) {
    read_line(buffer, SIZE);
    char *token = strtok(buffer, " ");
    *n = 0;
    while (token != NULL) {
        (*n)++;
        token = strtok(NULL, " ");
    }
    int *a = (int*)malloc(*n * sizeof(int));
    rewind(stdin);
    read_line(buffer, SIZE);
    token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        a[i] = atoi(token) - 1;
        token = strtok(NULL, " ");
        i++;
    }
    return a;
}

int main() {
    int n, m;
    n = read_int();
    m = read_int();
    int *p = read_int_array(&n);
    initialize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        x = read_ints();
        y = read_ints();
        unite(x - 1, y - 1);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) {
            s++;
        }
    }
    printf("%d\n", s);
    free(p);
    return 0;
}
