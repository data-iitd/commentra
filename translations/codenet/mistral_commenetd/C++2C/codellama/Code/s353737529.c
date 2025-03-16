/*
これを入れて実行
gcc code.c
./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to check if first pair has greater second value than second pair
int greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

//-----------------------Main function-----------------------
int main(void){
	// Input the number of digits in binary representation
	int n;
	scanf("%d", &n);

	// Initialize an empty string 's' to store binary representation
	char s[1000000];
	s[0] = '\0';

	// Check if the number is zero and print '0' if it is
	if(n == 0){
		printf("0\n");
		return 0;
	}

	// Iterate through the number from the least significant bit to the most significant bit
	int i = 1;
	while(n != 0){
		// If the number is even, add '0' to the binary representation
		if(n % 2 == 0){
			strcat(s, "0");
		} else {
			// If the number is odd, add '1' to the binary representation
			strcat(s, "1");
		}

		// Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
		n -= abs(n % 2);

		// Update the number by dividing it by -2 (since we subtracted the remainder in the previous step, we need to divide by -2 to get the next number)
		n /= -2;
	}

	// Reverse the binary representation and print it
	int len = strlen(s);
	for(int i = 0; i < len / 2; i++){
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}

	printf("%s\n", s);
}

