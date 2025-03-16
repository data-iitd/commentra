
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    int v[100010];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    int vo[100010];
    int ve[100010];
    int vt[100010];
    memset(vo, 0, sizeof(vo));
    memset(ve, 0, sizeof(ve));
    memset(vt, 0, sizeof(vt));
    for(int i = 0; i < n; i++)
    {
        vt[v[i]]++;
        if(i % 2 == 0)
        {
            ve[v[i]]++;
        }
        else
        {
            vo[v[i]]++;
        }
    }
    int ans = 0;
    if(vo[0] + ve[0] == vt[0])
    {
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    }
    else
    {
        ans = n - vo[0] - ve[0];
    }
    printf("%d\n", ans);
    return 0;
}

