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
    int n,k;
    scanf("%d %d",&n,&k);
    char s[n];
    scanf("%s",s);
    int cards[26]={0};
    for(int i=0;i<n;i++)
    {
        cards[s[i]-'A']++;
    }
    long long ans=0;
    for(int i=0;i<k;i++)
    {
        int change=cards[25];
        if(change>k-i)
        {
            change=k-i;
        }
        ans+=(change*change);
        cards[25]-=change;
        i+=change-1;
    }
    printf("%lld\n",ans);
    return 0;
}
