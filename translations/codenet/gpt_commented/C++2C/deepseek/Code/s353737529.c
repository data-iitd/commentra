#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Direction vectors for moving in 4 directions (up, right, down, left)
int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

// Constants for infinity and modulo operations
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

// Comparator function to sort pairs based on the second element
int greaterSecond(const int* f, const int* s){
    return f[1] > s[1];
}

// Function to compute the greatest common divisor (GCD) using recursion
int gcd(int a, int b){
	if (b == 0) return a; // Base case: if b is 0, return a
	return gcd(b, a % b); // Recursive case
}

//-----------------------ここから-----------

int main(void){
    int n; // Variable to hold the input number

    // Read an integer from standard input
	scanf("%d", &n);

    // Initialize an empty string to hold the binary representation
	char s[100];
    // Special case: if the input number is 0, output '0' and exit
	if(n == 0){
		printf("0\n");
		return 0;
	}
	
    // Loop to convert the number to its binary representation in a specific format
	int i = 1;
	while(n != 0){
        // Check if the current number is even or odd
		if(n % 2 == 0){
			s[i-1] = '0'; // Append '0' for even numbers
		} else {
			s[i-1] = '1'; // Append '1' for odd numbers
		}

        // Adjust the number for the next iteration
		n -= abs(n % 2); // Reduce n by 1 if it's odd
		n /= -2; // Divide n by -2 to continue the conversion
        i++;
	}

    // Reverse the string to get the correct binary representation
    for(int j = 0; j < i / 2; j++){
        char temp = s[j];
        s[j] = s[i-j-2];
        s[i-j-2] = temp;
    }
    s[i-1] = '\0'; // Null-terminate the string

    // Output the final binary string
	printf("%s\n", s);

}
