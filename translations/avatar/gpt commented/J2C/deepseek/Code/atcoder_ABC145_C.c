#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int pos[N][2];
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    
    double sum = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            sum += sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
        }
    }
    
    printf("%.15f\n", sum / N);
    
    return 0;
}
