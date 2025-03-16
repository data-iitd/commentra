#include <stdio.h>

int main() {
    int A, B;
    int ans = 0;
    int out = 1;
    scanf("%d %d", &A, &B);

    while (out < B) {
        out--;
        out += A;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
