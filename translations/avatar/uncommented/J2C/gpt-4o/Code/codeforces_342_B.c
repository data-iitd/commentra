#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 1000
#define MAX_T 1000

typedef struct {
    int start;
    int end;
} Interval;

int main() {
    int m, s, f;
    scanf("%d %d %d", &m, &s, &f);
    
    Interval map[MAX_T + 1];
    int maxT = -1;
    
    for (int i = 0; i < m; i++) {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        map[k].start = a;
        map[k].end = b;
        if (k > maxT) {
            maxT = k;
        }
    }
    
    char actions[MAX_M + MAX_T]; // Assuming maximum length of actions
    int actionIndex = 0;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1, b = -1;

    for (int t = 1; t <= maxT; t++) {
        if (map[t].start != 0 || map[t].end != 0) { // Check if the interval is set
            a = map[t].start;
            b = map[t].end;
        }
        if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) {
            actions[actionIndex++] = 'X';
        } else {
            actions[actionIndex++] = M;
            cur += d;
        }
        if (cur == f) break;
    }
    
    while (cur != f) {
        actions[actionIndex++] = M;
        cur += d;
    }
    
    actions[actionIndex] = '\0'; // Null-terminate the string
    printf("%s\n", actions);
    
    return 0;
}
