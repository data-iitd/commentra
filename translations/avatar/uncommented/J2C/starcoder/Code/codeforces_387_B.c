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
#include <limits.h>
#include <stdbool.h>
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
#include <limits.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int n, m, i, j, ans;
    scanf("%d %d", &n, &m);
    int req[n], pre[m];
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);
    for(i = 0; i < m; i++)
        scanf("%d", &pre[i]);
    i = n - 1;
    j = m - 1;
    ans = 0;
    while(i >= 0 && j >= 0)
    {
        if(req[i] > pre[j])
            ans++;
        else
            j--;
        i--;
    }
    printf("%d", ans + i + 1);
    return 0;
}

