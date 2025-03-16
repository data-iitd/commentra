#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
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

int main(void){
    int n,k,ans,L,ans2;
    char s[100000];
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    L=s[0];
    int cnt=0;
    for(int i=1;i<n;i++){
        if(L==s[i])cnt++;
        else {
            L=s[i];
            ans+=cnt;
            ans2++;
            cnt=0;
        }
    }
    ans+=cnt;
    ans2++;
    printf("%lld\n",ans+min(2*k,ans2-1));
    }
