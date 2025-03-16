
#include <stdio.h>

int main() {
int n, k, z;
scanf("%d %d", &n, &k);
n++;
if (n % k!= 0) {
z = k - n % k;
}
printf("%d\n", n + z);
return 0;
}
// 