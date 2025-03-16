#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define N 200010

ll a[N], q[N], n, tot;

<<<<<<< HEAD
=======
int compare(const void *a, const void *b) {
    return (*(ll *)a - *(ll *)b);
}

>>>>>>> 98c87cb78a (data updated)
ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void write(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

void writeln(ll x) {
    write(x);
    puts("");
}

<<<<<<< HEAD
int compare(const void *a, const void *b) {
    return (*(ll *)a - *(ll *)b);
}

=======
>>>>>>> 98c87cb78a (data updated)
int main() {
    n = read();
    for (ll i = 1; i <= n; ++i) {
        a[i] = read();
    }
    qsort(a + 1, n, sizeof(ll), compare);
    for (ll i = 1; i <= n; ++i) {
        if (a[i] == a[i + 1]) {
            q[++tot] = a[i];
            i++;
        }
    }
    writeln(q[tot] * q[tot - 1]);
    return 0;
}

// <END-OF-CODE>
