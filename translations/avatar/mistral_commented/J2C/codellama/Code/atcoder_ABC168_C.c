#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int A, B, H, M;
    double ans, dkaku, dans2;
    double AA2, BB2, CC, DD;
    double mkaku, hkaku, kaku;

    // Reading the input values
    scanf("%d %d %d %d", &A, &B, &H, &M);

    // Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku = M * 6;
    hkaku = H * 30 + M / 2;

    // Calculating kaku (difference between mkaku and hkaku)
    kaku = mkaku - hkaku;

    // Calculating the absolute value of kaku in radians
    dkaku = fabs(kaku * 0.01745329251994329576923690768489);

    // Calculating the squared values of A and B
    AA2 = A * A;
    BB2 = B * B;

    // Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
    CC = AA2 + BB2;
    DD = cos(dkaku) * A * B;

    // Calculating the answer (square root of the difference between CC and DD)
    ans2 = CC - DD;
    dans2 = sqrt(ans2);
    ans = dans2;

    // Printing the answer
    printf("%.0lf\n", ans);

    // End of code
    return 0;
}
