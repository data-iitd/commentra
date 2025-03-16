
#include <stdio.h>
#include <string.h>

int main() {
	char s1[100], s2[100], s3[100];
	scanf("%s %s %s", s1, s2, s3);

	char s1s[100], s2s[100], s3s[100];
	strcpy(s1s, s1);
	strcpy(s2s, s2);
	strcpy(s3s, s3);

	printf("%c%c%c\n", toupper(s1s[0]), toupper(s2s[0]), toupper(s3s[0]));
}

