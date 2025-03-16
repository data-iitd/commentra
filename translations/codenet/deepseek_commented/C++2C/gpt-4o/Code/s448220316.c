#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
int read() {
=======
inline int read() {
>>>>>>> 98c87cb78a (data updated)
    int k = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        k = k * 10 + ch - '0';
        ch = getchar();
    }
    return k * f;
}

<<<<<<< HEAD
void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
=======
inline void write(int x) {
    if (x < 0) x = -x, putchar('-');
>>>>>>> 98c87cb78a (data updated)
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

<<<<<<< HEAD
void writeln(int x) {
=======
inline void writeln(int x) {
>>>>>>> 98c87cb78a (data updated)
    write(x);
    puts("");
}

int n, m, l, r, vi, fa[100005], v[200005];

<<<<<<< HEAD
int get(int x) {
=======
inline int get(int x) {
>>>>>>> 98c87cb78a (data updated)
    if (x == fa[x]) return x;
    int f = get(fa[x]);
    v[x] += v[fa[x]];
    return fa[x] = f;
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        l = read();
        r = read();
        vi = read();
        int li = get(l), ri = get(r);
        if (li != ri) {
            v[ri] = vi - v[r] + v[l];
            fa[ri] = li;
        } else {
            if (v[r] - v[l] != vi) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}

// <END-OF-CODE>
