#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int A, B, H, M;
    double ans;

    // Reading the input values
    scanf("%d %d %d %d", &A, &B, &H, &M);

    // Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    double mkaku = M * 6.0;
    double hkaku = H * 30.0 + M * 0.5;

    // Calculating kaku (difference between mkaku and hkaku)
    double kaku = fabs(mkaku - hkaku);

    // Calculating the absolute value of kaku in radians
    double dkaku = fabs(kaku * M_PI / 180.0);

    // Calculating the squared values of A and B
    double AA2 = A * A;
    double BB2 = B * B;

    // Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
    double CC = AA2 + BB2;
    double DD = cos(dkaku) * A * B;

    // Calculating the answer (square root of the difference between CC and DD)
    double ans2 = CC - DD;
    ans = sqrt(ans2);

    // Printing the answer
    printf("%.20f\n", ans);

    return 0;
}
