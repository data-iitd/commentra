#include <stdio.h>
#include <string.h>
int main()
{
    char S[1000001];
    char T[1000001];
    char U[1000001];
    scanf("%s",S);
    scanf("%s",T);
    scanf("%s",U);
    int A = 0;
    int B = 0;
    for(int i=0;i<strlen(S);i++)
    {
        if(S[i]==U[0])
        {
            A++;
        }
    }
    for(int i=0;i<strlen(T);i++)
    {
        if(T[i]==U[0])
        {
            B++;
        }
    }
    if(S[0]==U[0])
    {
        A--;
    }
    if(T[0]==U[0])
    {
        B--;
    }
    printf("%d %d",A,B);
    return 0;
}
