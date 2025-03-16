#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <assert.h>
#include <complex.h>
#include <errno.h>
#include <fenv.h>
#include <locale.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <wchar.h>
#include <wctype.h>


int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  long long sum = 0;
  for(int b = 1; b <= n; b++){
    int cnt = (n+1)/b;
    int md = (n+1)%b;
    sum+=cnt*max((b-k),0)+max((md-k),0);
    if(k==0) sum--;
  }
  printf("%lld\n",sum);
  return 0;
}