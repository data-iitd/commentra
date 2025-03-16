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
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
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
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int N, T;
    scanf("%d %d", &N, &T);
    int AB[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }
    int dp[N + 1][6001];
    for (int i = 0; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }
    printf("%d", dp[N][6000]);
    return 0;
}

