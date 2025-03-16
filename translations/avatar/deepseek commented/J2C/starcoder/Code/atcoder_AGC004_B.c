#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
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
#include <stdarg.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int N;
    long x;
    scanf("%d %ld", &N, &x);
    long srimeList[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }
    long costList[N][N];
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[(i - castNum + N) % N])? costList[i][castNum - 1] : srimeList[(i - castNum + N) % N];
        }
    }
    long result[N];
    for (int i = 0; i < N; i++) {
        result[i] = i * x + 0;
        for (int j = 0; j < N; j++) {
            result[i] += costList[i][j];
        }
    }
    printf("%ld", result[0]);
    for (int i = 1; i < N; i++) {
        printf(" %ld", result[i]);
    }
    printf("\n");
    return 0;
}

