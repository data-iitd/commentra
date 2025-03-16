#include <stdio.h>

void solve(int tc) {
    int a;
    scanf("%d", &a);
    printf("%d\n", (a == 0) ? 1 : 0);
}

int main() {
    int tcs = 1;
    int tc = 1;
    while (tc <= tcs) {
        solve(tc);
        tc++;
    }
    return 0;
}

// <END-OF-CODE>
