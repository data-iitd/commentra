#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);
    int arr[NUM];
    int map[NUM];
    int bin = 0;
    int diff = 0;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        map[arr[i]] = i;
    }
    for(int i = 0; i < N; i++)
    {
        if((bin % 2)!= (map[arr[i]] % 2))
        {
            diff++;
        }
        bin++;
        bin %= 2;
    }
    int ans = (diff / 2);
    printf("%d", ans);
    return 0;
}

