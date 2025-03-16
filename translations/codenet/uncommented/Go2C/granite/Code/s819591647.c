
//problem_b.c

#include <stdio.h>
#include <stdlib.h>

#define constMod 100000007

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
    char** ss = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        ss[i] = (char*)malloc(sizeof(char) * 100);
        scanf("%s", ss[i]);
    }
    return (int*)ss;
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
        if ((double)a[i] >= rate) {
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

