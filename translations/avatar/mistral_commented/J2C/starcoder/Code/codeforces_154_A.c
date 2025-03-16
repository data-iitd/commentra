#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char arr[100000];
    scanf("%s",arr);
    int N=strlen(arr);
    int K;
    scanf("%d",&K);
    int res=0;
    for(int k=0;k<K;k++)
    {
        char input[100000];
        scanf("%s",input);
        int a=0,b=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]==input[0])
                a++;
            else if(arr[i]==input[1])
                b++;
            else
            {
                res+=min(a,b);
                a=b=0;
            }
        }
        res+=min(a,b);
    }
    printf("%d",res);
    return 0;
}

