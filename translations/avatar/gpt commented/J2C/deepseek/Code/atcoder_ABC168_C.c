#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);

    double mkaku = M * 6.0;
    double hkaku = H * 30.0 + M * 0.5;
    double kaku = fabs(mkaku - hkaku);
    if (kaku > 180) {
        kaku = 360 - kaku;
    }
    double dkaku = kaku * M_PI / 180.0;

    double AA2 = A * A;
    double BB2 = B * B;
    double CC = AA2 + BB2;
    double DD = 2 * A * B * cos(dkaku);
    double ans2 = CC - DD;
    double ans = sqrt(ans2);

    printf("%.10f\n", ans);
    return 0;
}
