#include<stdio.h>
#include<string.h>
char str1[100],str2[100],temp[100];
int main()
{
    int i,j=0,t;
    scanf("%s[^\n]",str1);
    scanf("%s[^\n]",str2);
    i=strlen(str1);
    t=i-1;
    if(strlen(str1)!=strlen(str2))
    {
        System.out.println("NO");
    }
    else
    {
        while(str1[j]!='\0')
        {
            temp[j]=str1[t];
            j++;
            t--;
        }
        t=0;
        i=0;
        while(temp[i]!='\0')
        {
            if(temp[i]==str2[i])
            {
                t++;
            }
            i++;
        }
        if(strlen(str2)==t)
        {
            System.out.println("YES");
        }
        else if(strlen(str2)!=t)
        {
            System.out.println("NO");
        }
    }
    return 0;
}
