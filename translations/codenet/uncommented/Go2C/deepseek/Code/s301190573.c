#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000000

char buffer[MAX_LINE_SIZE];
int *par, *rank;

void nextLine(char *line, size_t *index) {
    size_t i = 0;
    while ((buffer[*index] != '\n') && (*index < MAX_LINE_SIZE)) {
        line[i++] = buffer[*index];
        (*index)++;
    }
    line[i] = '\0';
    (*index)++;
}

int *nextIntArray() {
    char line[MAX_LINE_SIZE];
    size_t index = 0;
    nextLine(line, &index);
    int *arr = (int *)malloc(strlen(line) * sizeof(int));
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }
    return arr;
}

void initialize(int n) {
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int root(int i) {
    if (par[i] == i) return i;
    par[i] = root(par[i]);
    return par[i];
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

int main() {
    char line[MAX_LINE_SIZE];
    size_t index = 0;
    nextLine(line, &index);
    int n, m;
    sscanf(line, "%d %d", &n, &m);
    int *p = nextIntArray();
    initialize(n);
    for (int i = 0; i < m; i++) {
        nextLine(line, &index);
        int x, y;
        sscanf(line, "%d %d", &x, &y);
        unite(x - 1, y - 1);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) s++;
    }
    printf("%d\n", s);
    free(par);
    free(rank);
    free(p);
    return 0;
}
