#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<float.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<float.h>

int main()
{
    int s[11];
    int i;
    for(i=0;i<10;i++){
        scanf("%d",&s[i]);
    }
    sort(s,s+10);
    for(i=9;i>6;i--){
        printf("%d\n",s[i]);
    }
    return 0;
}
