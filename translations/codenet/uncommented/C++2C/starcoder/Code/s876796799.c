#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <stdarg.h>
#include <stddef.h>

int main(){
  int N;
  scanf("%d", &N);
  long long a[200000];
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]);
  }
  long long ans = 0;
  for(int i = 0; i < N; i++){
    long long left_border;
    long long right_border;
    long long cur_ind = a[i] - 1;
    long long left_ind = -1;
    long long right_ind = -1;
    for(int j = 0; j < i; j++){
      if(a[j] < a[i]){
        if(left_ind == -1 || a[j] > a[left_ind]){
          left_ind = j;
        }
      }
    }
    for(int j = i + 1; j < N; j++){
      if(a[j] > a[i]){
        if(right_ind == -1 || a[j] < a[right_ind]){
          right_ind = j;
        }
      }
    }
    if(left_ind == -1){
      left_border = -1;
    } else {
      left_border = a[left_ind];
    }
    if(right_ind == -1){
      right_border = N;
    } else {
      right_border = a[right_ind];
    }
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);
  }
  printf("%lld\n", ans);
  return 0;
}

