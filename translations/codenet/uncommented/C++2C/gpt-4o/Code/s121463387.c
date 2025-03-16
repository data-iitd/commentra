#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n, x;
<<<<<<< HEAD
    char s[12]; // Enough to hold integers up to 32-bit
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        x = i;
        sprintf(s, "%d", x); // Convert integer to string
        if (x % 3 == 0 || x % 10 == 3) {
=======
    char s[12]; // Enough to hold integers up to 32 bits
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        x = i;
        sprintf(s, "%d", x); // Convert integer to string
        if(x % 3 == 0 || x % 10 == 3) {
>>>>>>> 98c87cb78a (data updated)
            printf(" %d", i);
            continue;
        } else {
            int k = strlen(s);
<<<<<<< HEAD
            while (k > 0) {
                k = k - 1;
                int j = pow(10, k);
                if ((x / j) % 10 == 3) {
=======
            while(k > 0) {
                k = k - 1;
                int j = pow(10, k);
                if((x / j) % 10 == 3) {
>>>>>>> 98c87cb78a (data updated)
                    printf(" %d", i);
                    break;
                }
            }
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
