
#include <stdio.h>

int main() {
int t, a, b, c, count = 0;
scanf("%d", &t);
while (t--) {
scanf("%d %d %d", &a, &b, &c);
if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
count++;
}
}
printf("%d", count);
return 0;
}
//END-OF-CODE