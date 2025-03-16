#include<stdio.h>
#include<string.h>

// Main function where the program execution begins
int main() {
	// Declare variables to store integers and a character
	int a, b;
	char S;
	
	// Infinite loop to continuously take input and perform operations
	while (1) {
		// Take input in the format a S b
		scanf("%d %c %d", &a, &S, &b);
		
		// Perform operations based on the value of S
		if (S == '+') printf("%d\n", a + b);
		if (S == '-') printf("%d\n", a - b);
		if (S == '*') printf("%d\n", a * b);
		if (S == '/') printf("%d\n", a / b);
		
		// Break the loop if S is '?'
		if (S == '?') break;
	}
}

