

#include <stdio.h>
#include <stdlib.h>

int main() {
 int n, i, temp, q, w, e;
 int *a, *b;
 int f = 0;

 scanf("%d", &n);
 a = (int*)malloc(n * sizeof(int));
 b = (int*)malloc(n * sizeof(int));

 temp = 0;
 q = 0;
 w = INT_MIN;
 e = INT_MIN;

 for (i = 0; i < n; i++) {
 scanf("%d %d", &a[i], &b[i]);

 if (temp < a[i]) {
 if (q > b[i]) {
 f = 1;
 }
 q = b[i];
 temp = a[i];
 }

 if (temp > a[i]) {
 if (q < b[i]) {
 f = 1;
 }
 q = b[i];
 temp = a[i];
 }

 if (a[i] > w) {
 w = a[i];
 if (b[i] < e) {
 f = 1;
 }
 }

 if (a[i] < w) {
 if (b[i] > e) {
 f = 1;
 }
 }
 }

 if (f == 1) {
 printf("Happy Alex\n");
 } else {
 printf("Poor Alex\n");
 }

 free(a);
 free(b);

 return 0;
}
