
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char s[1000];
	scanf("%s", s);
	int n = strlen(s);
	int v[26]={};
	for (int i = 0;i < n;i++)v[s[i] - 'a']++;
	char ans[10] = "Yes";
	for (int i = 0;i < 26;i++) {
		if (v[i] % 2!= 0) {
			ans[0] = 'N';
			ans[1] = 'o';
			break;
		}
	}
	printf("%s\n", ans);
}
