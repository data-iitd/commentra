#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000000
#define MAX_SIZE 1000000

long long l[MAX_SIZE];
int count = 0;

void gen(long long number, int four, int seven) {
    if (number > LIMIT) {
        return;
    }
    if (number > 0 && four == seven) {
        l[count++] = number;
    }
    gen(number * 10 + 4, four + 1, seven);
    gen(number * 10 + 7, four, seven + 1);
}

int main() {
    gen(0, 0, 0);
    qsort(l, count, sizeof(long long), (int (*)(const void *, const void *))compare);
    
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    for (int i = 0; i < count; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

// <END-OF-CODE>
