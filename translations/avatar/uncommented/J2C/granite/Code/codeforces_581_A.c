
#include <stdio.h>

int main() {
int a, b;
scanf("%d %d", &a, &b);
int count = 0;
while (a > 0 && b > 0) {
count++;
a--;
b--;
}
int ans = a / 2 + b / 2;
printf("%d %d\n", count, ans);
return 0;
}
// END-OF-CODE