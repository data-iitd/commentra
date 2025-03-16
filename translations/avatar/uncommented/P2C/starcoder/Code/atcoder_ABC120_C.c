#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
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
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(void) {
    char s[100000];
    scanf("%s",s);
    int ans = 0;
    int len = strlen(s);
    int cnt[26] = {0};
    for(int i = 0;i < len;i++) {
        cnt[s[i] - 'a']++;
    }
    for(int i = 0;i < 26;i++) {
        ans += cnt[i] / 2;
    }
    printf("%d\n",ans);
    return 0;
}

