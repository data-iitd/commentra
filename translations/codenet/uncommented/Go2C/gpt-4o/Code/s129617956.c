#include <stdio.h>
#include <math.h>

int min(int i, int j) {
    return (i < j) ? i : j;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int rt = (int)sqrt(n);
    int minf = 100;

    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;

            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = min(minf, ndigit);
        }
    }
    printf("%d\n", minf);
    return 0;
}

/* <END-OF-CODE> */
