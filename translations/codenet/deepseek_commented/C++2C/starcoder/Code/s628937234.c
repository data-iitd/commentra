#include <stdio.h>
#include <string.h>

int main()
{
	char s[1000], t[1000];
	
	scanf("%s", s);
	
	t[0] = s[0];
	t[1] = '\0';
	strcat(t, to_string(strlen(s) - 2));
	strcat(t, s[strlen(s) - 1]);
	
	printf("%s\n", t);
}

