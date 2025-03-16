
#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    int mx = A + B;
    mx = A - B > mx ? A - B : mx;
    mx = A * B > mx ? A * B : mx;
    printf("%d\n", mx);
    return 0;
}

