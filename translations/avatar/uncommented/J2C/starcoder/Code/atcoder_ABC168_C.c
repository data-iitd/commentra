#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);
    double kaku, mkaku, hkaku, ans2, AA, BB, HH, MM, AA2, BB2, CC, DD, dkaku, dans2;
    mkaku = M * 6;
    hkaku = H * 30 + M / 2;
    kaku = mkaku - hkaku;
    dkaku = fabs(kaku * 3.14159265358979323846 / 180);
    AA = A * A;
    BB = B * B;
    AA2 = AA + BB;
    BB2 = AA * BB;
    CC = AA2 + BB2;
    DD = cos(dkaku) * 2 * AA * BB;
    ans2 = CC - DD;
    dans2 = ans2;
    ans = sqrt(dans2);
    printf("%.2f\n", ans);
    return 0;
}

