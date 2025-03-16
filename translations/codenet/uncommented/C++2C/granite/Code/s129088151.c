
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int n;
	char str[10], com[13];
	bool *T;

	scanf("%d", &n);
	T = (bool*)malloc(sizeof(bool)*100000);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", com, str);
		if (com[0] == 'i')T[strlen(str)] = true;
		else {
			if (T[strlen(str)]) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
