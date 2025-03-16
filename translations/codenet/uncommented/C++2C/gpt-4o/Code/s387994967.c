#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    
    if (A < 13 && A >= 6) {
        printf("%d\n", B / 2);
    }
    if (A < 6) {
        printf("0\n");
    }
    if (A >= 13) {
        printf("%d\n", B);
    }

    return 0;
}

// <END-OF-CODE>
