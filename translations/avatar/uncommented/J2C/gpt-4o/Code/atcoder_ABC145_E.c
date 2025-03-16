#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int value;
} Item;

int compare(const void *a, const void *b) {
    return ((Item *)a)->time - ((Item *)b)->time;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    
    Item *AB = (Item *)malloc(N * sizeof(Item));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i].time, &AB[i].value);
    }
    
    qsort(AB, N, sizeof(Item), compare);
    
    int dp[N + 1][6001] = {0};
    
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];
            int time = AB[i - 1].time;
            int value = AB[i - 1].value;
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = (dp[i][timeAfterEat] > dp[i - 1][timeAfterEat - time] + value) ? 
                                      dp[i][timeAfterEat] : 
                                      (dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }
    
    int max_value = 0;
    for (int j = 0; j <= 6000; j++) {
        if (dp[N][j] > max_value) {
            max_value = dp[N][j];
        }
    }
    
    printf("%d\n", max_value);
    
    free(AB);
    return 0;
}

// <END-OF-CODE>
