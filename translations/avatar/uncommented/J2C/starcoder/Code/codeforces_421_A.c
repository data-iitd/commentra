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

int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int list1[a],list2[b];
    for(int i=0;i<a;i++)
    {
        scanf("%d",&list1[i]);
    }
    for(int i=0;i<b;i++)
    {
        scanf("%d",&list2[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(list1[i]==1)
        {
            printf("1 ");
        }
        else
        {
            printf("2 ");
        }
    }
    return 0;
}

