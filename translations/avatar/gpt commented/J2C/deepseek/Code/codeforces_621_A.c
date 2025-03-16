#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    long long list[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &list[i]);
    }
    
    long long sum = 0;
    long long odd[n];
    int odd_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 0) {
            sum += list[i];
        } else {
            odd[odd_count++] = list[i];
        }
    }
    
    qsort(odd, odd_count, sizeof(long long), compare);
    
    for (int i = 0; i < odd_count; i++) {
        sum += odd[i];
    }
    
    if (odd_count % 2 != 0) {
        sum -= odd[0];
    }
    
    printf("%lld\n", sum);
    
    return 0;
}
