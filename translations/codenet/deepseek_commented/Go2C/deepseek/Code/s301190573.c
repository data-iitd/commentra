#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

char buffer[SIZE];
int par[SIZE], rank[SIZE];

char* NextLine() {
    char* line = fgets(buffer, SIZE, stdin);
    if (line == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }
    return line;
}

int* NextInts() {
    char* line = NextLine();
    int* nums = (int*)malloc(2 * sizeof(int));
    char* token = strtok(line, " ");
    nums[0] = atoi(token);
    token = strtok(NULL, " ");
    nums[1] = atoi(token);
    return nums;
}

int* NextIntArray() {
    char* line = NextLine();
    int* nums = (int*)malloc(sizeof(int) * SIZE);
    char* token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        nums[count++] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }
    return nums;
}

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
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
    int n, m;
    int* p;
    int x, y;
    int s = 0;

    int* nm = NextInts();
    n = nm[0];
    m = nm[1];
    p = NextIntArray();

    initialize(n);

    for (int i = 0; i < m; i++) {
        int* xy = NextInts();
        unite(xy[0] - 1, xy[1] - 1);
        free(xy);
    }

    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) s++;
    }

    printf("%d\n", s);

    free(p);
    free(nm);
    return 0;
}
