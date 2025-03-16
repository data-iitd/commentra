#include <bits/stdc++.h>
using namespace std;

/* sort */
struct pair {
    int index;
    int p1, p2;
};
struct pairs {
    pair *data;
    int size;
    int max_size;
};

int cmp(const void *a, const void *b) {
    return ((pair *)a)->index - ((pair *)b)->index;
}

void init(pairs *p) {
    p->data = (pair *)malloc(sizeof(pair));
    p->size = 0;
    p->max_size = 1;
}

void push(pairs *p, int index, int p1, int p2) {
    if (p->size >= p->max_size) {
        p->max_size *= 2;
        p->data = (pair *)realloc(p->data, sizeof(pair) * p->max_size);
    }
    p->data[p->size].index = index;
    p->data[p->size].p1 = p1;
    p->data[p->size].p2 = p2;
    p->size++;
}

void sort_pairs(pairs *p) {
    qsort(p->data, p->size, sizeof(pair), cmp);
}

/* sort */

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

/*==========================================
 *             Library
 *==========================================*/

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, int init) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < sizeof(res) / sizeof(res[0]); i++) {
        copy(res[i:], res, i);
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, int init) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < res.size(); i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, int init) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < res.size(); i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, int init, int n) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        copy(res[i:], res, i);
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, int init, int n) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, int init, int n) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < sizeof(res) / sizeof(res[0]); i++) {
        copy(res[i:], res, i);
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < res.size(); i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < res.size(); i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init, int n) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        copy(res[i:], res, i);
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init, int n) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init, int n) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        res[i] = init;
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init, int n, int m) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = init;
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init, int n, int m) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = init;
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init, int n, int m) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = init;
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init, int n, int m, int o) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                res[i][j][k] = init;
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init, int n, int m, int o) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                res[i][j][k] = init;
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init, int n, int m, int o) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                res[i][j][k] = init;
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init, int n, int m, int o, int p) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    res[i][j][k][l] = init;
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init, int n, int m, int o, int p) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    res[i][j][k][l] = init;
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init, int n, int m, int o, int p) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    res[i][j][k][l] = init;
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init, int n, int m, int o, int p, int q) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    for (int r = 0; r < q; r++) {
                        res[i][j][k][l][r] = init;
                    }
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init, int n, int m, int o, int p, int q) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    for (int r = 0; r < q; r++) {
                        res[i][j][k][l][r] = init;
                    }
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init, int n, int m, int o, int p, int q) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    for (int r = 0; r < q; r++) {
                        res[i][j][k][l][r] = init;
                    }
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T *res, T init, int n, int m, int o, int p, int q, int r) {
    if (res == NULL) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    for (int s = 0; s < q; s++) {
                        for (int t = 0; t < r; t++) {
                            res[i][j][k][l][s][t] = init;
                        }
                    }
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(T &res, T init, int n, int m, int o, int p, int q, int r) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    for (int s = 0; s < q; s++) {
                        for (int t = 0; t < r; t++) {
                            res[i][j][k][l][s][t] = init;
                        }
                    }
                }
            }
        }
    }
}

// 配列の要素をすべて初期化する
template <typename T>
void ini(vector<T> &res, T init, int n, int m, int o, int p, int q, int r) {
    if (res.empty()) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                for (int l = 0; l < p; l++) {
                    for (int s = 0; s < q; s++) {
                        for (int t = 0; t < r; t++) {
                            res[i][j][k][l][s][t] = init;
                        }
                    }
                }
            }
        }
    }