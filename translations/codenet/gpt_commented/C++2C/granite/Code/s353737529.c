
/*
これを入れて実行
gcc code.c
./a.out
 */

#include <stdio.h>

int main(void){
    int n; // Variable to hold the input number

    // Read an integer from standard input
	scanf("%d", &n);

    // Initialize an empty string to hold the binary representation
	char s[1000] = "";

    // Special case: if the input number is 0, output '0' and exit
	if(n == 0){
		printf("0\n");
		return 0;
	}
	
    // Loop to convert the number to its binary representation in a specific format
	int i = 1;
	while(n!= 0){
        // Check if the current number is even or odd
		if(n % 2 == 0){
			strcat(s, "0"); // Append '0' for even numbers
		} else {
			strcat(s, "1"); // Append '1' for odd numbers
		}

        // Adjust the number for the next iteration
		n -= abs(n % 2); // Reduce n by 1 if it's odd
		n /= -2; // Divide n by -2 to continue the conversion
	}

    // Output the final binary string
	printf("%s\n", s);

}
