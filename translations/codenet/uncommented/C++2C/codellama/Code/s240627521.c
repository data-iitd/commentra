#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<time.h>
#include<ctype.h>
#include<assert.h>
#include<errno.h>
#include<float.h>
#include<iso646.h>
#include<locale.h>
#include<setjmp.h>
#include<signal.h>
#include<stdalign.h>
#include<stdarg.h>
#include<stdatomic.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<time.h>
#include<wchar.h>
#include<wctype.h>

int main() {
  int N;
  scanf("%d", &N);
  int* A = (int*)malloc(N*sizeof(int));
  for(int i=0;i<N;++i) scanf("%d", &A[i]);
  qsort(A, N, sizeof(int), compare);
  int index;
  int max = INT_MAX;
  for(int i=1;i<N;++i) {
    if(max>abs(A[0]-2*A[i])) {
      max = abs(A[0]-2*A[i]);
      index = i;
    }
  }
  printf("%d %d\n", A[0], A[index]);
  free(A);
}

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

