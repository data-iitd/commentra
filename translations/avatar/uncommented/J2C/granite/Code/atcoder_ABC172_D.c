
#include <stdio.h>

int main() {
int n;
scanf("%d", &n);
long long ans = 0;
for (int i = 1; i <= n; i++) {
ans += (long long)i * (n / i) * (n / i + 1) / 2;
}
printf("%lld\n", ans);
return 0;
}
// END-OF-CODE