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

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),compare);
    int ans=0;
    for(int i=0;i<k;i++)
        ans+=a[i];
    printf("%d",ans);
    return 0;
}

int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

