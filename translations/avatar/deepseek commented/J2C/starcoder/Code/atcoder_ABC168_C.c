
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);
    
    double mkaku = M * 6;
    double hkaku = H * 30 + M / 2;
    double kaku = mkaku - hkaku;
    
    double ans = sqrt(A*A + B*B - 2*A*B*cos(kaku));
    
    printf("%.2f\n", ans);
    
    return 0;
}

