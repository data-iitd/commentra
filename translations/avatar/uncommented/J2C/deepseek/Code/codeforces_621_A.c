#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    long list[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &list[i]);
    }
    long odd[n];
    int odd_size = 0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 0) {
            sum += list[i];
        } else {
            odd[odd_size++] = list[i];
        }
    }
    qsort(odd, odd_size, sizeof(long), compare);
    for (int i = 0; i < odd_size; i++) {
        sum += odd[i];
    }
    if (odd_size % 2 != 0) {
        sum -= odd[0];
    }
    printf("%ld\n", sum);
    return 0;
}
