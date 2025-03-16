#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int round_complexity[n];
    int george_complexity[m];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    
    for (int j = 0; j < m; j++) {
        scanf("%d", &george_complexity[j]);
    }
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (round_complexity[i] <= george_complexity[j]) {
            i++;
        }
        j++;
    }
    
    printf("%d\n", n - i);
    return 0;
}

// <END-OF-CODE>
