
// ACM-ICPCアジア地区予選2014 B. Miscalculation

#include <stdio.h>
#include <string.h>

char str[100000];

// This function multiplies consecutive digits until it encounters a '+' or the end of the string.
int mul(int idx){
	int res = str[idx]-'0';
	while(idx+1 < strlen(str) && str[idx+1]=='*'){
		idx += 2;
		res *= str[idx]-'0';
	}
	return res;
}

// This function adds the results of multiple calls to mul by handling '+' operations.
int add(int idx){
	int res = mul(idx);
	while(idx+1 < strlen(str) && str[idx+1] == '+'){
		idx += 2;
		res += mul(idx);
	}
	return res;
}

// This function performs the same operations as add but uses a different approach.
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
	int d;
	while(scanf("%s %d", str, &d)!= EOF){
		int idx = 0;
		int a = add(idx);  // Calculate the result using the add function
		idx = 0;
		int b = bob(idx);  // Calculate the result using the bob function
		if(a == d){
			printf("%c\n", (b == d? 'U' : 'M'));  // Output based on both results
		} else {
			printf("%c\n", (b == d? 'L' : 'I'));  // Output based on both results
		}
	}
}
