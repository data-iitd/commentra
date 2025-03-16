#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
typedef struct Scanner {
    char* buf;
    int buf_size;
    int buf_pos;
    char* str;
    int str_size;
    int str_pos;
} Scanner;

Scanner* NewScanner() {
    Scanner* sc = (Scanner*)malloc(sizeof(Scanner));
    sc->buf_size = 1024;
    sc->buf_pos = 0;
    sc->buf = (char*)malloc(sc->buf_size * sizeof(char));
    sc->str_pos = 0;
    sc->str_size = 0;
    sc->str = NULL;
    return sc;
}

char* nextStr(Scanner* sc) {
    if (sc->str_pos == sc->str_size) {
        sc->str_pos = 0;
        sc->str_size = 0;
        sc->str = NULL;
        sc->buf_pos = 0;
        while (1) {
            if (sc->buf_pos == sc->buf_size) {
                sc->buf_size *= 2;
                sc->buf = (char*)realloc(sc->buf, sc->buf_size * sizeof(char));
            }
            int c = getchar();
            if (c == EOF) {
                break;
            }
            sc->buf[sc->buf_pos++] = c;
            if (c == ' ' || c == '\n') {
                sc->buf[sc->buf_pos] = '\0';
                sc->str_size = sc->buf_pos;
                sc->str = (char*)malloc(sc->str_size * sizeof(char));
                memcpy(sc->str, sc->buf, sc->str_size * sizeof(char));
                break;
            }
        }
    }
    char* ret = sc->str + sc->str_pos;
    sc->str_pos += strlen(ret) + 1;
    return ret;
}

int nextInt(Scanner* sc) {
    char* str = nextStr(sc);
    int ret = atoi(str);
    return ret;
}

double nextFloat(Scanner* sc) {
    char* str = nextStr(sc);
    double ret = atof(str);
    return ret;
}

char* nextRuneSlice(Scanner* sc) {
    char* str = nextStr(sc);
    int len = strlen(str);
    char* ret = (char*)malloc((len + 1) * sizeof(char));
    memcpy(ret, str, len * sizeof(char));
    ret[len] = '\0';
    return ret;
}

int* nextIntSlice(Scanner* sc, int n) {
    int* ret = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ret[i] = nextInt(sc);
    }
    return ret;
}

double* nextFloatSlice(Scanner* sc, int n) {
    double* ret = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ret[i] = nextFloat(sc);
    }
    return ret;
}

// Arithmetic
int max(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m < nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int min(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m > nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int abs(int x) {
    if (x > 0) {
        return x;
    }
    return -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

// Sort
typedef struct Val {
    int id;
    int num;
} Val;

typedef struct ByNum {
    Val* vals;
    int n;
} ByNum;

int cmp(const void* a, const void* b) {
    Val* va = (Val*)a;
    Val* vb = (Val*)b;
    return va->num - vb->num;
}

ByNum* newByNum(int n) {
    ByNum* bn = (ByNum*)malloc(sizeof(ByNum));
    bn->vals = (Val*)malloc(n * sizeof(Val));
    bn->n = n;
    return bn;
}

void sortByNum(ByNum* bn) {
    qsort(bn->vals, bn->n, sizeof(Val), cmp);
}

int main() {
    Scanner* sc = NewScanner();
    int A, B, C, K;
    A = nextInt(sc);
    B = nextInt(sc);
    C = nextInt(sc);
    K = nextInt(sc);
    int ma = max(A, B, C);
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }
    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }
    printf("%d\n", ma + rest);
    return 0;
}

