#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main(void) {
  int N;
  scanf("%d", &N);
  int64_t A[N];
  rep(i, N) scanf("%" PRId64, &A[i]);

  int64_t answer = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int64_t diff = abs(A[i] - A[j]);
      answer = max(answer, diff);
    }
  }
  printf("%" PRId64 "\n", answer);
  return 0;
}
