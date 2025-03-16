
#include <stdio.h>

int main() {
int n, k, l = 0, c = 1;
scanf("%d %d", &n, &k);
for (int i = 0; i < n; i++) {
int a;
scanf("%d", &a);
if (a == l) c += 1;
else c = 1;
l = a;
}
if (c + k > n) printf("%d\n", n - c);
else printf("-1\n");
return 0;
}
//END-OF-CODE