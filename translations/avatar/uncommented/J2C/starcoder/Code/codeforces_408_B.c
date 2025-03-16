#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
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
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    char s1[1000000];
    char s2[1000000];
    scanf("%s", s1);
    scanf("%s", s2);
    if (isValid(s1, s2) == false)
    {
        printf("-1\n");
    }
    else
    {
        int ans = 0;
        int n1 = strlen(s1);
        int n2 = strlen(s2);
        int m1[26] = {0};
        int m2[26] = {0};
        for (int i = 0; i < n1; i++)
        {
            m1[s1[i] - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            m2[s2[i] - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            if (m1[s2[i] - 'a'] > 0 && m2[s2[i] - 'a'] > 0)
            {
                int x1 = m1[s2[i] - 'a'];
                int x2 = m2[s2[i] - 'a'];
                x1 = (x1 < x2)? x1 : x2;
                ans += x1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

bool isValid(char *s1, char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    bool map[26] = {false};
    for (int i = 0; i < n1; i++)
    {
        map[s1[i] - 'a'] = true;
    }
    for (int i = 0; i < n2; i++)
    {
        if (map[s2[i] - 'a'] == false)
        {
            return false;
        }
    }
    return true;
}

