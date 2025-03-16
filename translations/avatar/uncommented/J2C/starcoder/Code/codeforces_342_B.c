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
#include <stdbool.h>
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
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int m, s, f, maxT;
    scanf("%d %d %d", &m, &s, &f);
    maxT = -1;
    int k;
    int a, b;
    int cur = s;
    int d = (s < f)? +1 : -1;
    char M = (s < f)? 'R' : 'L';
    char *actions = (char *)malloc(sizeof(char) * 1000000);
    for (int i = 0; i < 1000000; i++)
    {
        actions[i] = '\0';
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &k, &a);
        maxT = (k > maxT)? k : maxT;
        scanf("%d", &b);
        if (k == maxT)
        {
            if (cur >= a && cur <= b)
            {
                strcat(actions, "X");
            }
            else if (cur + d >= a && cur + d <= b)
            {
                strcat(actions, "X");
            }
            else
            {
                strcat(actions, M);
                cur += d;
            }
        }
        else
        {
            if (cur >= a && cur <= b)
            {
                strcat(actions, "X");
            }
            else if (cur + d >= a && cur + d <= b)
            {
                strcat(actions, "X");
            }
            else
            {
                strcat(actions, M);
                cur += d;
            }
        }
    }
    while (cur!= f)
    {
        strcat(actions, M);
        cur += d;
    }
    printf("%s", actions);
    return 0;
}

