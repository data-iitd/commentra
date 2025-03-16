


#include <stdio.h>
#include <string.h>

int main() {
	char a[1000000];
	scanf("%s", a);
	char *tmp = strstr(a, "1");
	while (tmp!= NULL) {
		*tmp = '0';
		tmp = strstr(a, "1");
	}
	tmp = strstr(a, "9");
	while (tmp!= NULL) {
		*tmp = '1';
		tmp = strstr(a, "9");
	}
	tmp = strstr(a, "0");
	while (tmp!= NULL) {
		*tmp = '9';
		tmp = strstr(a, "0");
	}
	printf("%s", a);
	return 0;
}

