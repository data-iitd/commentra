#include <stdio.h>
#include <string.h>
int main()
{
    int K;
    char S[100000];
    scanf("%d", &K);
    scanf("%s", S);
    if(strlen(S) <= K)
    {
        printf("%s\n", S);
    }
    else
    {
        printf("%.*s...\n", K, S);
    }
    return 0;
}
