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

int main()
{
    int n, m, i, ans;
    scanf("%d %d", &n, &m);
    int q1[n], q2[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &q1[i]);
        q2[i] = i + 1;
    }
    ans = 0;
    while (n > 0)
    {
        if (q1[0] <= m)
        {
            q1[0] = q1[n - 1];
            q1[n - 1] = INT_MIN;
            n--;
            ans = q2[0];
            q2[0] = q2[n];
            q2[n] = INT_MIN;
        }
        else if (q1[0] > m)
        {
            q1[0] -= m;
            q1[n] = q1[0];
            q1[0] = INT_MIN;
            n++;
            q2[0] = q2[n - 1];
            q2[n - 1] = INT_MIN;
        }
    }
    printf("%d", ans);
    return 0;
}

