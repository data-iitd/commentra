
#include <stdio.h>
#include <string.h>
int main()
{
	char s[100], t[100];
	scanf("%s", s);
	t[0] = s[0];
	t[1] = s[s[0] - 2];
	t[2] = s[s[0] - 1];
	printf("%s\n", t);
}

