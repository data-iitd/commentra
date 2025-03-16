#include <stdio.h>
#include <string.h>

int mul(const char* str, int* idx){
	int res = str[*idx]-'0';
	while(*idx+1 < strlen(str) && str[*idx+1]=='*'){
		(*idx) += 2;
		res *= str[*idx]-'0';
	}
	return res;
}

int add(const char* str, int* idx){
	int res = mul(str, idx);
	while(*idx+1 < strlen(str) && str[*idx+1] == '+'){
		(*idx) += 2;
		res += mul(str, idx);
	}
	return res;
}

int bob(const char* str, int* idx){
	int res = str[*idx]-'0';
	while(*idx+1 < strlen(str)){
		if(str[*idx+1] == '+') res += str[*idx+2]-'0';
		else                  res *= str[*idx+2]-'0';
		(*idx) += 2;
	}
	return res;
}

int main(){
	char s[1000]; int d;
	while(scanf("%s %d", s, &d) != EOF){
		int idx = 0;
		int a = add(s, &idx);
		idx = 0;
		int b = bob(s, &idx);
		if(a == d){
			printf("%s\n", (b == d ? "U" : "M"));
		} else {
			printf("%s\n", (b == d ? "L" : "I"));
		}
	}
}
