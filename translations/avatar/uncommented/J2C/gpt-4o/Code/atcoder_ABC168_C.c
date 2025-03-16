#include <stdio.h>
#include <math.h>

int main() {
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);

    double AA = (double)A;
    double BB = (double)B;
    double HH = (double)H;
    double MM = (double)M;
    double kaku, mkaku, hkaku, AA2, BB2, CC, DD, dkaku, dans2;

    mkaku = MM * 6.0;
    hkaku = HH * 30.0;
    hkaku += (double)M / 2.0;
    kaku = mkaku - hkaku;
    dkaku = fabs(kaku * M_PI / 180.0); // Convert degrees to radians

    AA2 = AA * AA;
    BB2 = BB * BB;
    CC = AA2 + BB2;
    DD = cos(dkaku) * 2.0 * AA * BB;
    dans2 = CC - DD;

    double ans = sqrt(dans2);
    printf("%lf\n", ans);

    return 0;
}

// <END-OF-CODE>
