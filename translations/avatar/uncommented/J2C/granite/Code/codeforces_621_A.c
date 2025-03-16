
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long *list = (long *)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        scanf("%ld", &list[i]);
    }
    long *odd = (long *)malloc((n / 2 + n % 2) * sizeof(long));
    int odd_count = 0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 0) {
            sum += list[i];
        } else {
            odd[odd_count++] = list[i];
        }
    }
    qsort(odd, odd_count, sizeof(long), cmpfunc);
    for (int i = 0; i < odd_count; i++) {
        sum += odd[i];
    }
    if (odd_count % 2!= 0) {
        sum -= odd[0];
    }
    printf("%ld\n", sum);
    free(list);
    free(odd);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(long*)a - *(long*)b );
}

