/*
これを入れて実行
gcc code.c
./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------ここから-----------

int main(void){
    int n; // Variable to hold the input number

    // Read an integer from standard input
	scanf("%d", &n);

    // Initialize an empty string to hold the binary representation
	char s[1000000];
	memset(s, 0, sizeof(s));

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
			s[i] = '0'; // Append '0' for even numbers
		} else {
			s[i] = '1'; // Append '1' for odd numbers
		}

        // Adjust the number for the next iteration
		n -= abs(n % 2); // Reduce n by 1 if it's odd
		n /= -2; // Divide n by -2 to continue the conversion
		i++;
	}

    // Reverse the string to get the correct binary representation
	int j = 0;
	while(s[j]!= '\0'){
		j++;
	}
	for(int k = 0; k < j / 2; k++){
		char temp = s[k];
		s[k] = s[j - k - 1];
		s[j - k - 1] = temp;
	}

    // Output the final binary string
	printf("%s\n", s);

}

