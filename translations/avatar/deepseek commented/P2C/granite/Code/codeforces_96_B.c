

#include <stdio.h>
#include <stdlib.h>

int main() {
    int limit = 10000000000;
    long long int n;
    scanf("%lld", &n);
    long long int *l = (long long int *)malloc(sizeof(long long int));
    int l_size = 0;

    // The gen function generates numbers containing only the digits 4 and 7 using recursion.
    void gen(long long int number, int four, int seven) {
        // If the number exceeds the limit, return without adding it to the list.
        if (number > limit) {
            return;
        }
        // If the number is positive and the count of 4's equals the count of 7's, add it to the list.
        if (number > 0 && four == seven) {
            l[l_size] = number;
            l_size++;
        }
        // Recursively generate numbers by adding 4 or 7 to the current number.
        gen(number * 10 + 4, four + 1, seven);
        gen(number * 10 + 7, four, seven + 1);
    }

    gen(0, 0, 0);  // Start generating numbers with 0, 0, 0 counts of 4's and 7's.
    qsort(l, l_size, sizeof(long long int), compare);  // Sort the list l to easily find the smallest valid number.
    int i;
    for (i = 0; i < l_size; i++) {
        if (l[i] >= n) {
            printf("%lld", l[i]);
            break;
        }
    }
    if (i == l_size) {
        printf("%lld", l[l_size - 1]);
    }
    free(l);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(long long int *)a - *(long long int *)b);
}

