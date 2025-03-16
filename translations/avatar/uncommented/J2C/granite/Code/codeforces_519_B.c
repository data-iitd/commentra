
#include <stdio.h>

int main() {
int n, a = 0, b = 0, c = 0, x, y;
scanf("%d", &n);
for (int i = 0; i < n; i++) scanf("%d", &a), a += b;
for (int i = 0; i < n - 1; i++) scanf("%d", &b), b += c;
for (int i = 0; i < n - 2; i++) scanf("%d", &c);
x = a - b, y = b - c;
printf("%d\n%d\n", x, y);
return 0;
}

