
#include <stdio.h>

int main() {
  	char str[10];
  	scanf("%s", str);
  	if (str[2] == str[3] && str[4] == str[5]) printf("Yes\n");
  	else printf("No\n");
}
