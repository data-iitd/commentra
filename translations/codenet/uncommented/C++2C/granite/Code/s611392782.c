
// ACM-ICPCアジア地区予選2014 B. Miscalculation

#include <stdio.h>
#include <string.h>

char str[100000];

int mul(int idx){
	int res = str[idx]-'0';
	while(idx+1 < strlen(str) && str[idx+1]=='*'){
		idx += 2;
		res *= str[idx]-'0';
	}
	return res;
}

int add(int idx){
	int res = mul(idx);
	while(idx+1 < strlen(str) && str[idx+1] == '+'){
		idx += 2;
		res += mul(idx);
	}
	return res;
}

int bob(int idx){
	int res = str[idx]-'0';
	while(idx+1 < strlen(str)){
		if(str[idx+1] == '+') res += str[idx+2]-'0';
		else                  res *= str[idx+2]-'0';
		idx += 2;
	}
	return res;
}

int main(){
	while(scanf("%s", str)!= EOF){
		int idx = 0;
		int a = add(idx);
		idx = 0;
		int b = bob(idx);
		if(a == d){
			printf("%c\n", (b == d? 'U' : 'M'));
		} else {
			printf("%c\n", (b == d? 'L' : 'I'));
		}
	}
}

