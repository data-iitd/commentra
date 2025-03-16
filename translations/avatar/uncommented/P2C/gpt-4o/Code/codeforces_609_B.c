#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int lst[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    int count[MAX_SIZE] = {0}; // Assuming the values in lst are within a certain range
    long long res = 0;

    for (int i = 0; i < n; i++) {
        count[lst[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[lst[i]] > 1) {
            res += n - i - count[lst[i]];
            count[lst[i]]--;
        } else {
            res += n - i - 1;
        }
    }

    printf("%lld\n", res);
    return 0;
}

// <END-OF-CODE>
