#include <stdio.h>

int main() {
	char n[100];
	scanf("%s", n);
	
	for (int i = 0; i < 3; i++) {
		if (n[i] == '7') {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	
	return 0;
}
