#include <stdio.h>
#include <stdlib.h>

long long limit = 10000000000;
long long l[100000]; // Assuming a large enough array size for the list
int l_size = 0; // To keep track of the number of elements in the list

void gen(long long number, int four, int seven) {
    if (number > limit) {
        return;
    }
    if (number > 0 && four == seven) {
        l[l_size++] = number;
    }
    gen(number * 10 + 4, four + 1, seven);
    gen(number * 10 + 7, four, seven + 1);
}

int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    gen(0, 0, 0);
    qsort(l, l_size, sizeof(long long), compare);
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < l_size; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
