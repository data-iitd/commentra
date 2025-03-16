
#include <stdio.h>
#include <stdlib.h>

#define constMod 1000000007

int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int* getIntSlice(int n) {
    int* ns = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

int* getStringSlice(int n) {
    char buf[1024];
    gets(buf);
    char* s = (char*)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        s[i] = buf[i];
    }
    return s;
}

void solve() {
    int n = getInt();
    int m = getInt();
    int* a = getIntSlice(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (4 * m);
        if (a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    solve();
    return 0;
}
