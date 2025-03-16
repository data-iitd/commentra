
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>
#include<stdarg.h>
#include<float.h>
#include<limits.h>
#include<setjmp.h>
#include<signal.h>
#include<errno.h>
#include<ctype.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include<fenv.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>
#include<stdarg.h>
#include<float.h>
#include<limits.h>
#include<setjmp.h>
#include<signal.h>
#include<errno.h>
#include<ctype.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include<fenv.h>

#define SIZE (1e5 * 2) + 13

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt[SIZE];
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int a[SIZE];
    int ans = 0;
    int m = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a[m] = cnt[i];
            m++;
        }
    }
    sort(a, a + m);
    m = m - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    printf("%d\n", ans);
}

