#include <stdio.h>
#include <string.h>
int main(void)
{
    char l[100];
    scanf("%s",l);
    char *s = l;
    char *p = strchr(l,'.');
    int i = atoi(p+1);
    if(s[strlen(s)-1] == '9')
        printf("GOTO Vasilisa.\n");
    else if(s[strlen(s)-1]!= '9' && i < 5)
        printf("%s\n",s);
    else
    {
        s = strdup(s);
        s[strlen(s)-1]++;
        printf("%s\n",s);
    }
    return 0;
}
