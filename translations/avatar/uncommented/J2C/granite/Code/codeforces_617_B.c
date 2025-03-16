
#include <stdio.h>

int main() {
int n;
scanf("%d", &n);
int arr[n];
int count = 0;
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
if (arr[i] == 1) {
count++;
}
}
if (count == 0) {
printf("0\n");
} else {
long long result = 1;
for (int i = 1; i < count; i++) {
result *= (i - (i - 1));
}
printf("%lld\n", result);
}
return 0;
}
//END-OF-CODE


