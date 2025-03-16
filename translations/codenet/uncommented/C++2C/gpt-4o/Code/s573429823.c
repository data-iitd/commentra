#include <stdio.h>

int main(void)
{
    // Your code here!
    unsigned long n;
    scanf("%lu", &n);
    int flg = 0; // Using int for boolean flag
    if (n < 4) {
        printf("No\n");
    } else {
<<<<<<< HEAD
        for (int i = 0; i <= (n / 4); i++) {
            for (int j = 0; j <= (n / 7); j++) {
=======
        for (unsigned long i = 0; i <= (n / 4); i++) {
            for (unsigned long j = 0; j <= (n / 7); j++) {
>>>>>>> 98c87cb78a (data updated)
                if ((i * 4 + j * 7) == n) {
                    flg = 1; // Set flag to true
                    break;
                }
            }
            if (flg) break;
        }
        if (flg) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

// <END-OF-CODE>
