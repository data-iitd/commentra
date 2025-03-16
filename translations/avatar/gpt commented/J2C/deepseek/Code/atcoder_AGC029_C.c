#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int n;
int a[MAX_N];
int s[MAX_N];

int isPossible(int k) {
    memset(s, 0, sizeof(s));
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= current) {
            if (k == 1) return 0;

            while (current >= 0 && s[current] >= a[i]) {
                s[current]--;
                current--;
            }

            int p = a[i] - 1;
            while (true) {
                if (p < 0) return 0;

                s[p]++;
                if (s[p] == k) {
                    s[p] = 0;
                    p--;
                } else {
                    break;
                }
            }
        }
        current = a[i];
    }
    return 1;
}

void solve() {
    int ng = 0;
    int ok = n;

    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
}

void set() {
    scanf("%d", &n);
    char buffer[100000];
    fgets(buffer, sizeof(buffer), stdin);
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        a[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    set();
    solve();
    return 0;
}
