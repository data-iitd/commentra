#include <stdio.h>
#include <string.h>

// This function multiplies consecutive digits until it encounters a '+' or the end of the string.
int mul(const char* str, int* idx){
	int res = str[*idx] - '0';
	while(str[*idx + 1] == '*'){
		(*idx) += 2;
		res *= str[*idx] - '0';
	}
	return res;
}

// This function adds the results of multiple calls to mul by handling '+' operations.
int add(const char* str, int* idx){
	int res = mul(str, idx);
	while(str[*idx + 1] == '+'){
		(*idx) += 2;
		res += mul(str, idx);
	}
	return res;
}

// This function performs the same operations as add but uses a different approach.
int bob(const char* str, int* idx){
	int res = str[*idx] - '0';
	while(str[*idx + 1] != '\0'){
		if(str[*idx + 1] == '+') res += str[*idx + 2] - '0';
		else                      res *= str[*idx + 2] - '0';
		(*idx) += 2;
	}
	return res;
}

int main(){
	char s[100];
	int d;
	while(scanf("%s %d", s, &d) != EOF){
		int idx = 0;
		int a = add(s, &idx);  // Calculate the result using the add function
		idx = 0;
		int b = bob(s, &idx);  // Calculate the result using the bob function
		if(a == d){
			printf("%s\n", (b == d ? "U" : "M"));  // Output based on both results
		} else {
			printf("%s\n", (b == d ? "L" : "I"));  // Output based on both results
		}
	}
}
