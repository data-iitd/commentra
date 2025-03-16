


#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char s[1000];

	scanf("%d %s", &n, s);

	printf("%d\n", strstr(s, "ABC")!= NULL);
}

