#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(a) (((a) > 0) ? (a) : (-a))

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int *data;
    int size;
    int capacity;
} Queue;

typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

typedef struct {
    int *data;
    int size;
    int capacity;
} intHeap;

typedef struct {
    point *data;
    int size;
    int capacity;
} points;

Queue *newQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * capacity);
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void push(Queue *q, int x) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->data = (int *)realloc(q->data, sizeof(int) * q->capacity);
    }
    q->data[q->size++] = x;
}

int pop(Queue *q) {
    if (q->size == 0) {
        return -1;
    }
    int res = q->data[--q->size];
    return res;
}

bool empty(Queue *q) {
    return q->size == 0;
}

Stack *newStack(int capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * capacity);
    s->size = 0;
    s->capacity = capacity;
    return s;
}

void push(Stack *s, int x) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[s->size++] = x;
}

int pop(Stack *s) {
    if (s->size == 0) {
        return -1;
    }
    int res = s->data[--s->size];
    return res;
}

bool empty(Stack *s) {
    return s->size == 0;
}

intHeap *newIntHeap(int capacity) {
    intHeap *h = (intHeap *)malloc(sizeof(intHeap));
    h->data = (int *)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void push(intHeap *h, int x) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (int *)realloc(h->data, sizeof(int) * h->capacity);
    }
    h->data[h->size++] = x;
    int i = h->size - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] < h->data[i]) {
            int tmp = h->data[p];
            h->data[p] = h->data[i];
            h->data[i] = tmp;
        } else {
            break;
        }
        i = p;
    }
}

int pop(intHeap *h) {
    if (h->size == 0) {
        return -1;
    }
    int res = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (i * 2 + 1 < h->size) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if (r < h->size && h->data[l] < h->data[r]) {
            l = r;
        }
        if (h->data[i] < h->data[l]) {
            int tmp = h->data[i];
            h->data[i] = h->data[l];
            h->data[l] = tmp;
        } else {
            break;
        }
        i = l;
    }
    return res;
}

bool empty(intHeap *h) {
    return h->size == 0;
}

points *newPoints(int capacity) {
    points *p = (points *)malloc(sizeof(points));
    p->data = (point *)malloc(sizeof(point) * capacity);
    p->size = 0;
    p->capacity = capacity;
    return p;
}

void push(points *p, point x) {
    if (p->size == p->capacity) {
        p->capacity *= 2;
        p->data = (point *)realloc(p->data, sizeof(point) * p->capacity);
    }
    p->data[p->size++] = x;
}

point pop(points *p) {
    if (p->size == 0) {
        point res = {0, 0};
        return res;
    }
    point res = p->data[--p->size];
    return res;
}

bool empty(points *p) {
    return p->size == 0;
}

int modpow(int a, int n, int mod) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        res = res * a % mod;
    }
    return res;
}

int modinv(int n, int mod) {
    return modpow(n, mod - 2, mod);
}

int modcomb(int n, int a, int mod) {
    int x = 1;
    int y = 1;
    for (int i = 0; i < a; i++) {
        x = x * (n - i) % mod;
        y = y * (i + 1) % mod;
    }
    return x * modpow(y, mod - 2, mod) % mod;
}

int modfactorial(int n, int mod) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}

int main() {
    int n, m, R;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &R);

    int *rs = (int *)malloc(sizeof(int) * R);
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--;
    }

    int **costs = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            costs[i][j] = INT_MAX;
        }
        costs[i][i] = 0;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // ワーシャルフロイド法で最短経路を算出
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // 順列で訪問先の順序をすべて試す
    // これでは重複して訪問する町がでてしまうか。。
    int **perms = (int **)malloc(sizeof(int *) * R);
    for (int i = 0; i < R; i++) {
        perms[i] = (int *)malloc(sizeof(int) * R);
        for (int j = 0; j < R; j++) {
            perms[i][j] = rs[j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < R; i++) {
        for (int j = 1; j < R; j++) {
            for (int k = 0; k < R; k++) {
                int tmp = 0;
                for (int l = 1; l < R; l++) {
                    int from = perms[i][l - 1];
                    int to = perms[i][l];
                    tmp += costs[from][to];
                }
                ans = min(ans, tmp);
            }
            int tmp = 0;
            for (int l = 1; l < R; l++) {
                int from = perms[i][l - 1];
                int to = perms[i][l];
                tmp += costs[from][to];
            }
            ans = min(ans, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}

