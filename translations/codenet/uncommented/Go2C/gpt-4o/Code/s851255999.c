#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int limit;
} work;

int compare(const void *a, const void *b) {
    return ((work *)a)->limit - ((work *)b)->limit;
}

int main() {
    int n;
    scanf("%d", &n);
    
    work *ws = malloc(n * sizeof(work));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }
    
    qsort(ws, n, sizeof(work), compare);
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        if (sum > ws[i].limit) {
            printf("No\n");
            free(ws);
            return 0;
        }
    }
    
    printf("Yes\n");
    free(ws);
    return 0;
}

// <END-OF-CODE>
