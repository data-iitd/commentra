#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)

#define read() read_()
#define write(x) write_(x)
#define writeln(x) write_(x), putchar('\n')

ll read_();
void write_(ll x);

const ll N=200010;
ll a[N], q[N], n, tot;

int main(){
    n = read();
    For(i,1,n) a[i] = read();
    std::sort(a+1, a+n+1);
    For(i,1,n)
        if (a[i] == a[i+1])
            q[++tot] = a[i], i++;
    writeln(q[tot] * q[tot-1]);
    return 0;
}

ll read_() {
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

void write_(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write_(x / 10);
    putchar(x % 10 + '0');
}
