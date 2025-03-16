#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if first pair has greater second value than second pair
int greaterSecond(const int* f, const int* s){
    return f[1] > s[1];
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

//-----------------------Main function-----------------------
int main(void){
	int n;

	// Input the number of digits in binary representation
	scanf("%d", &n);

	// Initialize an empty string 's' to store binary representation
	char s[100];
	memset(s, 0, sizeof(s));

	// Check if the number is zero and print '0' if it is
	if(n == 0){
		printf("0\n");
		return 0;
	}

	// Iterate through the number from the least significant bit to the most significant bit
	int i = 0;
	while(n != 0){
		// If the number is even, add '0' to the binary representation
		if(n % 2 == 0){
			s[i++] = '0';
		} else {
			// If the number is odd, add '1' to the binary representation
			s[i++] = '1';
		}

		// Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
		n -= abs(n % 2);

		// Update the number by dividing it by -2 (since we subtracted the remainder in the previous step, we need to divide by -2 to get the next number)
		n /= -2;
	}

	// Reverse the binary representation and print it
	for(int j = i - 1; j >= 0; j--){
		printf("%c", s[j]);
	}
	printf("\n");
}
