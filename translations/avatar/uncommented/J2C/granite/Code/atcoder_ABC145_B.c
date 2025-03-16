
#include <stdio.h>
#include <string.h>

int main() {
char a[100005], b[100005], str[100005];
int n;
scanf("%d", &n);
gets(str);
gets(str);
for (int i = 0; i < n / 2; i++) {
a[i] = str[i];
}
if (strcmp(str, a) == 0) {
printf("Yes\n");
} else {
printf("No\n");
}
return 0;
}
// END-OF-CODE