
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int VP, VD, T, F, C;
    scanf("%d %d %d %d %d", &VP, &VD, &T, &F, &C);
    
    if (VD <= VP) {
        printf("0\n");
        return 0;
    }
    
    int answer = 0;
    double start = T;
    
    while (1) {
        double x = start * VP / (VD - VP);
        if ((start + x) * VP >= C) {
            break;
        }
        start += 2 * x + F;
        answer++;
    }
    
    printf("%d\n", answer);
    return 0;
}

