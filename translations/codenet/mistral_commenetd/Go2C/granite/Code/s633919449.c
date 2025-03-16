
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 10000000
#define mod 1e9 + 7

typedef struct {
    int n;
    int **edges;
} Graph;

Graph *NewGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int *)malloc(sizeof(int) * n);
    }
    return g;
}

void dfs(int c, int **edges, int *visited) {
    visited[c] = 1;
    for (int i = 0; i < edges[c][0]; i++) {
        int v = edges[c][i + 1];
        if (visited[v] == 0) {
            dfs(v, edges, visited);
        }
    }
}

void bfs(int c, Graph *g) {
    int next[maxBufSize];
    int nextSize = 0;
    int *visited = (int *)malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    next[nextSize++] = c;
    visited[c] = 1;
    while (nextSize > 0) {
        int u = next[--nextSize];
        for (int i = 0; i < g->edges[u][0]; i++) {
            int v = g->edges[u][i + 1];
            if (visited[v] == 0) {
                visited[v] = 1;
                next[nextSize++] = v;
            }
        }
    }
    free(visited);
}

int getInt() {
    int c;
    while ((c = getchar())!= EOF) {
        if (c >= '0' && c <= '9') {
            ungetc(c, stdin);
            break;
        }
    }
    int x = 0;
    scanf("%d", &x);
    return x;
}

int *getIntArray(int n) {
    int *array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

char *getString() {
    int c;
    while ((c = getchar())!= EOF) {
        if (c!='' && c!= '\n') {
            ungetc(c, stdin);
            break;
        }
    }
    if (c == EOF) {
        return NULL;
    }
    int size = 0;
    char *str = (char *)malloc(sizeof(char) * maxBufSize);
    while ((c = getchar())!= EOF && c!= '\n') {
        str[size++] = c;
    }
    str[size] = '\0';
    return str;
}

char **getStringArray(int n) {
    char **array = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        array[i] = getString();
    }
    return array;
}

int abs(int a) {
    return (a < 0)? -a : a;
}

int pow(int p, int q) {
    int res = 1;
    for (int i = 0; i < q; i++) {
        res *= p;
    }
    return res;
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % mod;
    } else {
        return (n * powMod(n, p - 1)) % mod;
    }
}

int min(int...nums) {
    if (nums[0] == 0) {
        printf("function min() requires at least one argument.");
        exit(1);
    }
    int res = nums[0];
    for (int i = 1; i < sizeof(nums) / sizeof(int); i++) {
        res = (res < nums[i])? res : nums[i];
    }
    return res;
}

int max(int...nums) {
    if (nums[0] == 0) {
        printf("function max() requires at least one argument.");
        exit(1);
    }
    int res = nums[0];
    for (int i = 1; i < sizeof(nums) / sizeof(int); i++) {
        res = (res > nums[i])? res : nums[i];
    }
    return res;
}

int strSearch(char **a, char *b) {
    for (int i = 0; i < sizeof(a) / sizeof(char *); i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

void printIntArray(int *array) {
    printf("[");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        printf("%d", array[i]);
        if (i!= sizeof(array) / sizeof(int) - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int calcMod(int x) {
    return x % mod;
}

char *reverse(char *s) {
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        res[i] = s[len - 1 - i];
    }
    return res;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int contains(int *s, int e) {
    for (int i = 0; i < sizeof(s) / sizeof(int); i++) {
        if (s[i] == e) {
            return 1;
        }
    }
    return 0;
}

int *makeRange(int min, int max) {
    int *res = (int *)malloc(sizeof(int) * (max - min + 1));
    for (int i = min; i <= max; i++) {
        res[i - min] = i;
    }
    return res;
}

int **powerset2(int *nums, int n) {
    int size = pow(2, n);
    int **result = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        result[i] = (int *)malloc(sizeof(int) * n);
        result[i][0] = 0;
    }
    int index = 0;
    result[index][0] = 0;
    index++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size; j++) {
            if (j & (1 << i)) {
                int max = index;
                for (int k = 0; k < max; k++) {
                    int *temp = (int *)malloc(sizeof(int) * (n + 1));
                    for (int l = 0; l < n + 1; l++) {
                        temp[l] = result[k][l];
                    }
                    for (int l = 0; l < n + 1; l++) {
                        result[index][l] = temp[l];
                    }
                    index++;
                }
            }
        }
    return result;
}

int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

int *getDivisor(int n) {
    int size = n + 1;
    int *divisor = (int *)malloc(sizeof(int) * size);
    divisor[0] = 1;
    if (n!= 1) {
        divisor[n] = n;
    }
    for (int i = 2; i < size; i++) {
        divisor[i] = i;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            divisor[j] = j;
        }
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k++) {
                divisor[k] = k;
            }
            for (int k = 0; k < size; k