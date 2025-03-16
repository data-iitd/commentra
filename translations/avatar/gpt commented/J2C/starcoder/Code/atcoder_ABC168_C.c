#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);
    double kaku, mkaku, hkaku, dkaku, dans2;
    mkaku = M * 6;
    hkaku = H * 30 + M / 2;
    kaku = mkaku - hkaku;
    dkaku = kaku * 3.14159265358979323846 / 180;
    dans2 = (A * A + B * B - 2 * A * B * cos(dkaku)) * 0.5;
    printf("%.2f\n", sqrt(dans2));
    return 0;
}

