#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main() {
	int n;
	char str[10], com[13];
	map<string, bool> T;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", com, str);
		if (com[0] == 'i')T[string(str)] = true;
		else {
			if (T[string(str)]) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
