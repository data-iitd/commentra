#include <stdio.h>
#include <string.h>

int main()
{
	char s[100], t[100];
	int i, j;
	
	scanf("%s", s);
	
	t[0] = s[0];
	
	for (i = 1, j = 1; i < strlen(s) - 1; i++, j++)
	{
		t[j] = s[i];
	}
	
	t[j] = '\0';
	
	printf("%s\n", t);
	
	return 0;
}

