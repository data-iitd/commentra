

#include <stdio.h>
#include <string.h>
int main()
{
	char s[100], t[100];
	scanf("%s", s);
	t[0] = s[0];
	sprintf(t+1, "%d", strlen(s)-2);
	t[strlen(s)-1] = s[strlen(s)-1];
	printf("%s\n", t);
}
