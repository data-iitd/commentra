#include <stdio.h>
#include <string.h>

int main() {
  	char str[100];
  	scanf("%s", str);
  	if (str[2] == str[3] && str[4] == str[5]) printf("Yes\n");
  	else printf("No\n");
}

