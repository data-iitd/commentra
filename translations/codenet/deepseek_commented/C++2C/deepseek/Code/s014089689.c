#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d", &n);
	char s[100];
	scanf("%s", s);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt++;
		int j = i + 1;
		for(; j < n; j++){
			if(s[i] != s[j]){
				break;
			}
		}
		i = j - 1;
	}
	printf("%d\n", cnt);
}
