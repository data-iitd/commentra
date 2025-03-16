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

int main(int argc, char **argv) {
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    Task tsk = new Task();
    printf("%d\n", tsk.solve(arr));
    return 0;
}

static class Task {
    public int solve(int arr[]) {
        int n = arr.length;
        int sorted[] = Arrays.copyOf(arr, n);
        Arrays.sort(sorted);
        long total = (long)n * (n + 1) / 2;
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int target = sorted[mid];
            int cur = 0;
            long cnt = 0;
            long bit[] = new long[2 * n + 2];
            for(int x = n + 1; x < bit.length; x += x & -x) bit[x]++;
            for(int i = 0; i < n; i++) {
                cur += arr[i] <= target? 1 : -1;
                for(int x = cur + n + 1; x < bit.length; x += x & -x) bit[x]++;
                for(int x = cur + n; x > 0; x -= x & -x) cnt += bit[x];
            }
            if(cnt >= total / 2 + 1) r = mid;
            else l = mid + 1;
        }
        return sorted[l];
    }
}

