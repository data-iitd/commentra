#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100000];
    scanf("%s",str);
    int oddCount = 0;
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        int count = 0;
        for(int j=0;j<len;j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }
        }
        if(count%2!=0)
        {
            oddCount++;
        }
    }
    if(oddCount<=1 || oddCount%2!=0)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    return 0;
}
