#include <stdio.h>

void solve(int n) {
    printf("%d\n", (n / 3) * 2 + (n % 3 == 0 ? 0 : 1));
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}

// <END-OF-CODE>
