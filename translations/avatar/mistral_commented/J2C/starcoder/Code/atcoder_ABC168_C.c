#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);
    double kaku, mkaku, hkaku, ans2, AA2, BB2, CC, DD, dkaku, dans2;
    mkaku = M * 6;
    hkaku = H * 30 + M / 2;
    kaku = mkaku - hkaku;
    dkaku = fabs(kaku * 3.14159265358979323846 / 180);
    AA2 = A * A;
    BB2 = B * B;
    CC = AA2 + BB2;
    DD = cos(dkaku) * A * B;
    ans2 = CC - DD;
    dans2 = ans2 * ans2;
    ans = sqrt(dans2);
    printf("%.10f\n", ans);
    return 0;
}

