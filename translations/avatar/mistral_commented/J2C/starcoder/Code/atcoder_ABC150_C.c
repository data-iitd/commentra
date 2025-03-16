
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 int n;
 scanf("%d", &n);
 char number[100000];
 for (int i = 1; i <= n; i++) {
 strcat(number, (char[]){i + 48});
 }
 int sum = 0;
 char line[100000][100000];
 while (scanf("%s", line[0])!= EOF) {
 for (int i = 0; i < n; i++) {
 if (strcmp(line[0], number) == 0) {
 sum += i;
 } else {
 sum -= i;
 }
 }
 }
 printf("%d\n", abs(sum));
 return 0;
}

