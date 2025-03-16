
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_N 1000000

int main(int argc, char *argv[]) {
 int n;
 int a[MAX_N];
 int i;
 int k;
 int current;
 int p;
 int sp;
 int ng;
 int ok;

 scanf("%d", &n);
 for (i = 0; i < n; i++) {
 scanf("%d", &a[i]);
 }

 ng = 0;
 ok = n;
 while (ok - ng > 1) {
 k = (ng + ok) / 2;
 if (isPossible(k, a, n)) {
 ok = k;
 } else {
 ng = k;
 }
 }

 printf("%d\n", ok);
 return 0;
}

bool isPossible(int k, int a[], int n) {
 int i;
 int current;
 int p;
 int sp;

 for (i = 0; i < n; i++) {
 if (a[i] <= current) {
 if (k == 1) return false;
 while (s[p] >= a[i]) {
 s[p]--;
 p--;
 }
 p = a[i] - 1;
 while (true) {
 if (p < 0) return false;
 sp = s[p] + 1;
 s[p] = sp;
 if (sp == k) {
 s[p]--;
 p--;
 } else {
 break;
 }
 }
 }
 current = a[i];
 }
 return true;
}

int s[MAX_N];

