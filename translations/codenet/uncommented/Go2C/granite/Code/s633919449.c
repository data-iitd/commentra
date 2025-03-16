
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 10000000
#define mod 1e9 + 7

int N;

struct Graph {
    int n;
    int **edges;
};

struct Graph *NewGraph(int n) {
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->n = n;
    g->edges = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int *)malloc(sizeof(int) * n);
    }
    return g;
}

void AddEdge(struct Graph *g, int u, int v) {
    g->edges[v][u] = 1;
    g->edges[u][v] = 1;
}

void dfs(int c, int **edges, int *visited) {
    visited[c] = 1;
    for (int i = 0; i < N; i++) {
        if (edges[c][i] == 1 && visited[i] == 0) {
            dfs(i, edges, visited);
        }
    }
}

void bfs(int c, struct Graph *g) {
    int *next = (int *)malloc(sizeof(int) * N);
    int next_size = 1;
    int *visited = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    next[0] = c;
    visited[c] = 1;
    for (int i = 0; i < next_size; i++) {
        int u = next[i];
        for (int j = 0; j < N; j++) {
            if (g->edges[u][j] == 1 && visited[j] == 0) {
                next[next_size] = j;
                visited[j] = 1;
                next_size++;
            }
        }
    }
    free(next);
    free(visited);
}

int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int *getIntArray(int n) {
    int *array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

char *getString() {
    char *str = (char *)malloc(sizeof(char) * maxBufSize);
    fgets(str, maxBufSize, stdin);
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
    return (int)abs((double)a);
}

int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

int min(int...nums) {
    if (sizeof...(nums) == 0) {
        printf("funciton min() requires at least one argument.");
        exit(1);
    }
    int res = nums[0];
    for (int i = 0; i < sizeof...(nums); i++) {
        res = (int)min((double)res, (double)nums[i]);
    }
    return res;
}

int max(int...nums) {
    if (sizeof...(nums) == 0) {
        printf("funciton max() requires at least one argument.");
        exit(1);
    }
    int res = nums[0];
    for (int i = 0; i < sizeof...(nums); i++) {
        res = (int)max((double)res, (double)nums[i]);
    }
    return res;
}

int strSearch(char **a, char *b) {
    for (int i = 0; i < N; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

void printIntArray(int *array) {
    char *strArray = malloc(sizeof(char) * N * 10);
    sprintf(strArray, "%d", array[0]);
    for (int i = 1; i < N; i++) {
        sprintf(strArray + strlen(strArray), " %d", array[i]);
    }
    printf("%s\n", strArray);
    free(strArray);
}

int calcMod(int x) {
    return x % mod;
}

char *reverse(char *s) {
    int len = strlen(s);
    char *rev = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - 1 - i];
    }
    return rev;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }
    int sqrtN = (int)sqrt((double)n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int contains(int *s, int e) {
    for (int i = 0; i < N; i++) {
        if (s[i] == e) {
            return 1;
        }
    }
    return 0;
}

int *makeRange(int min, int max) {
    int *a = (int *)malloc(sizeof(int) * (max - min + 1));
    for (int i = 0; i < max - min + 1; i++) {
        a[i] = min + i;
    }
    return a;
}

int **powerset2(int *nums) {
    int length = (int)pow(2, (double)N);
    int ***result = (int ***)malloc(sizeof(int **) * length);
    for (int i = 0; i < length; i++) {
        result[i] = (int **)malloc(sizeof(int *) * N);
        for (int j = 0; j < N; j++) {
            result[i][j] = (int *)malloc(sizeof(int) * N);
        }
    }
    int index = 0;
    result[index] = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        result[index][i] = (int *)malloc(sizeof(int) * N);
    }
    index++;
    for (int i = 0; i < N; i++) {
        int max = index;
        for (int j = 0; j < max; j++) {
            result[index] = copyAndAppend(result[j], nums[i]);
            index++;
        }
    }
    int ***res = (int ***)malloc(sizeof(int **) * length);
    for (int i = 0; i < length; i++) {
        res[i] = (int **)malloc(sizeof(int *) * N);
        for (int j = 0; j < N; j++) {
            res[i][j] = (int *)malloc(sizeof(int) * N);
        }
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j][k] = result[i][j][k];
            }
        }
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < N; j++) {
            free(result[i][j]);
        }
        free(result[i]);
    }
    free(result);
    return res;
}

int *copyAndAppend(int *nums, int n) {
    int *dst = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i < N; i++) {
        dst[i] = nums[i];
    }
    dst[N] = n;
    return dst;
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
    int *divisor = (int *)malloc(sizeof(int) * n);
    divisor[0] = 1;
    if (n!= 1) {
        divisor[1] = n;
    }
    int sqrtN = (int)sqrt((double)n);
    for (int i = 2; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            divisor[N] = i;
            divisor[N + 1] = n / i;
        }
    }
    int *divisorArray = (int *)malloc(sizeof(int) * N);
    int index = 0;
    divisorArray[index] = 1;
    index++;
    for (int i = 0; i < N; i++) {
        divisorArray[index] = n;
        index++;
    }
    return divisorArray;
}

int **makeRange2(int min, int max) {
    int **a = (int **)malloc(sizeof(int *) * (max - min + 1))
    for (int i = min; i <= max; i++) {
        a[i - min] = i;
    }
    return a;
}

int **powerset2(int *nums) {
    int length = (int)pow(2, (double)N);
    int ***result = (int ***)malloc(sizeof(int **) * length)
    for (int i = 0; i < length; i++) {
        result[i] = (int **)malloc(sizeof(int *) * N)
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
        }
    }
    int index = 0;
    result[index] = (int *)malloc(sizeof(int) * N)
    for (int i = 0; i < N; i++) {
        result[index][i] = 1;
        index++;
    }
    int ***res = (int ***)malloc(sizeof(int **) * length)
    for (int i = 0; i < length; i++) {
        res[i] = (int **)malloc(sizeof(int *) * N)
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
        }
    }
    return res;
}

int **makeRange(int min, int max) {
    int *a = (int *)malloc(sizeof(int) * (max - min + 1)
    for (int i = min; i <= max; i++) {
        a[i - min] = i;
    }
    return a;
}

int **powerset2(int *nums) {
    int length = (int)pow(2, (double)N)
    int ***result = (int ***)malloc(sizeof(int **) * length)
    for (int i = 0; i < length; i++) {
        result[i] = (int *)malloc(sizeof(int) * N)
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
        }
    }
    return result;
}

int factMod(int n) {
    int value = 1;
    for ; n > 1; n-- {
        value = calcMod(value * n)
        for ; n > 1; n-- {
            value = calcMod(value * n)
        }
    }
    return value
}

int **makeRange2(int min, int max) {
    int **a = (int **)malloc(sizeof(int *) * N)
    for ; n > 1; n-- {
        a[n] = n;
        a[n+1] = n;
        a[n+2] = n;
        a[n+3] = n;
        a[n+4] = n;
        a[n+5] = n;
        a[n+6] = n;
        a[n+7] = n;
        a[n+8] = n;
        a[n+9] = n;
        a[n+10] = n;
        a[n+11] = n;
        a[n+12] = n;
        a[n+13] = n;
        a[n+14] = n;
        a[n+15] = n;
        a[n+16] = n;
        a[n+17] = n;
        a[n+18] = n;
        a[n+19] = n;
        a[n+20] = n;
        a[n+21] = n;
        a[n+22] = n;
        a[n+23] = n;
        a[n+24] = n;
        a[n+25] = n;
        a[n+26] = n;
        a[n+27] = n;
        a[n+28] = n;
        a[n+29] = n;
        a[n+30] = n;
        a[n+31] = n;
        a[n+32] = n;
        a[n+33] = n;
        a[n+34] = n;
        a[n+35] = n;
        a[n+36] = n;
        a[n+37] = n;
        a[n+38] = n;
        a[n+39] = n;
        a[n+40] = n;
        a[n+41] = n;
        a[n+42] = n;
        a[n+43] = n;
        a[n+44] = n;
        a[n+45] = n;
        a[n+46] = n;
        a[n+47] = n;
        a[n+48] = n;
        a[n+49] = n;
        a[n+50] = n;
        a[n+51] = n;
        a[n+52] = n;
        a[n+53] = n;
        a[n+54] = n;
        a[n+55] = n;
        a[n+56] = n;
        a[n+57] = n;
        a[n+58] = n;
        a[n+59) = n;
        a[n+60] = n;
        a[n+61] = n;
        a[n+62] = n;
        a[n+63] = n;
        a[n+64] = n;
        a[n+65] = n;
        a[n+66] = n;
        a[n+67] = n;
        a[n+68] = n;
        a[n+69) = n;
        a[n+70] = n;
        a[n+71) = n;
        a[n+72] = n;
        a[n+73] = n;
        a[n+74] = n;
        a[n+75) = n;
        a[n+76) = n;
        a[n+77) = n;
        a[n+78) = n;
        a[n+79) = n;
        a[n+80) = n;
        a[n+81) = n;
        a[n+82) = n;
        a[n+83) = n;
        a[n+84) = n;
        a[n+85) = n;
        a[n+86) = n;
        a[n+87) 