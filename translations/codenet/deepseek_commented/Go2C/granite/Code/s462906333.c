
#include <stdio.h>
#include <stdlib.h>

#define abcd "abcdefghijklnmopqrstuvwxyz"
#define ABCD "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define dy {1, 1, 0, -1, -1, -1, 0, 1}
#define dx {0, 1, 1, 1, 0, -1, -1, -1}

#define dx {0, 1, 0, -1}
#define dy {1, 0, -1, 0}

#define inf 1e14 // Define a large value to represent infinity for cost comparisons

#define mod 1000000007

// ---------------------------------------------------------
int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int n, x, a[100000], v[100000], ans = inf;
    fscanf(fp, "%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
        v[i] = a[i];
    }

    for (int k = 0; k < n; k++) {
        int kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = (v[i] < a[n + i - k]? v[i] : a[n + i - k]);
            } else {
                v[i] = (v[i] < a[i - k]? v[i] : a[i - k]);
            }
            kans += v[i];
        }
        ans = (ans < kans + k * x? ans : kans + k * x);
    }

    printf("%d\n", ans);

    fclose(fp);
    return 0;
}

// ---------------------------------------------------------

// Pair is liked C++ pair
typedef struct {
    int a, b;
} Pair;

// Pairs is sorted by []Pair struct
typedef struct {
    Pair *p;
    int len;
} Pairs;

int cmpfunc(const void *a, const void *b) {
    Pair *aa = (Pair *)a;
    Pair *bb = (Pair *)b;
    if (aa->a < bb->a) {
        return -1;
    } else if (aa->a == bb->a) {
        return (aa->b < bb->b? -1 : (aa->b > bb->b? 1 : 0));
    }
    return 1;
}

// -------------------------------
int in(int c, int a, int z) {
    return (c >= a && c < z);
}

int btoi(int b) {
    return (b? 1 : 0);
}

int itob(int a) {
    return (a == 0? 0 : 1);
}

int max(int...a) {
    int r = a[0];
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

int min(int...a) {
    int r = a[0];
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

int minmax(int a, int b) {
    return (a > b? b : a);
}

int abs(int a) {
    return (a < 0? -a : a);
}

int sum(int...a) {
    int r = a[0];
    if (sizeof(a) / sizeof(a[0]) > 1) {
        for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++) {
            r += a[i];
        }
    }
    return r;
}

// ---------- buffered scanner -----------------------------------------
typedef struct {
    FILE *r;
    char buf[100000];
    int p;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->r = fopen("input.txt", "r");
    s->p = 0;
    return s;
}

char *next(Scanner *s) {
    s->pre();
    int start = s->p;
    for (; s->p < sizeof(s->buf); s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *Line(Scanner *s) {
    s->pre();
    int start = s->p;
    s->p = sizeof(s->buf);
    char *result = (char *)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int Int(Scanner *s) {
    int v;
    sscanf(s->next(), "%d", &v);
    return v;
}

int Int64(Scanner *s) {
    long long v;
    sscanf(s->next(), "%lld", &v);
    return v;
}

void pre(Scanner *s) {
    if (s->p >= sizeof(s->buf)) {
        s->readLine();
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    s->p = 0;
    while (fgets(s->buf + s->p, sizeof(s->buf) - s->p, s->r)!= NULL) {
        s->p += strlen(s->buf + s->p);
        if (s->buf[s->p - 1] == '\n') {
            s->buf[s->p - 1] = '\0';
            break;
        }
    }
}

// END-OF-CODE