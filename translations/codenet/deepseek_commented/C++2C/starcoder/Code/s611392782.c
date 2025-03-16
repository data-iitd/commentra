#include <stdio.h>
#include <string.h>

int mul(char* str, int* idx){
	int res = str[*idx]-'0';
	while(*idx+1 < strlen(str) && str[*idx+1]=='*'){
		(*idx) += 2;
		res *= str[*idx]-'0';
	}
	return res;
}

int add(char* str, int* idx){
	int res = mul(str, idx);
	while(*idx+1 < strlen(str) && str[*idx+1] == '+'){
		(*idx) += 2;
		res += mul(str, idx);
	}
	return res;
}

int bob(char* str, int* idx){
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
	while(scanf("%s %d", s, &d) == 2){
		int idx = 0;
		int a = add(s, &idx);  // Calculate the result using the add function
		idx = 0;
		int b = bob(s, &idx);  // Calculate the result using the bob function
		if(a == d){
			printf("%c\n", (b == d? 'U' : 'M'));  // Output based on both results
		} else {
			printf("%c\n", (b == d? 'L' : 'I'));  // Output based on both results
		}
	}
}

