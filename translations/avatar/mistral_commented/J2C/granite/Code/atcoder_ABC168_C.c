
#include <stdio.h>
#include <math.h>

int main() {
    int A, B, H, M;
    scanf("%d %d %d %d", &A, &B, &H, &M);

    double ans = 0;
    double mkaku = M * 6;
    double hkaku = H * 30 + M / 2;
    double kaku = fabs(mkaku - hkaku);
    double dkaku = kaku * M_PI / 180;
    double CC = A * A + B * B;
    double DD = cos(dkaku) * A * B;
    double ans2 = CC - DD;
    ans = sqrt(ans2);

    printf("%lf\n", ans);

    return 0;
}
// END-OF-CODE