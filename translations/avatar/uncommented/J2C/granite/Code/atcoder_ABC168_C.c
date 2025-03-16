
#include <stdio.h>
#include <math.h>

int main(void) {
int A, B, H, M;
scanf("%d %d %d %d", &A, &B, &H, &M);
double AA = A, BB = B, HH = H, MM = M;
double ans2;
double kaku;
double mkaku;
double hkaku;
double AA2;
double BB2;
double CC;
double DD;
double dkaku;
double dans2;
mkaku = MM * 6;
hkaku = HH * 30 + (double)M / 2;
kaku = mkaku - hkaku;
dkaku = fabs(kaku * M_PI / 180);
AA2 = AA * AA;
BB2 = BB * BB;
CC = AA2 + BB2;
DD = 2 * cos(dkaku) * AA * BB;
ans2 = CC - DD;
dans2 = ans2;
double ans = sqrt(dans2);
printf("%lf\n", ans);
return 0;
}
// END-OF-CODE