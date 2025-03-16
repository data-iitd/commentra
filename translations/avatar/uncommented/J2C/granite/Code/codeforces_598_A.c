
#include <stdio.h>

int main() {
int q;
scanf("%d", &q);
while (q--) {
int n;
scanf("%d", &n);
long long s = 0;
int x = (int) (log(n) / log(2));
x++;
s = -1 * pow(2, x) + 2 + (n * (n + 1)) / 2 - pow(2, x);
printf("%lld\n", s);
}
return 0;
}
//END-OF-CODE