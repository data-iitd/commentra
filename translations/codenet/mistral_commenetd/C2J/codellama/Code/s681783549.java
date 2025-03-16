#include <stdio.h>  // Include standard input/output library
#include <stdlib.h>  // Include standard library for memory allocation

public class Main {  // Beginning of the main class
	public static void main(String[] args){  // Beginning of the main function
		int i;  // Declare an integer variable 'i'
		char S[6];  // Declare a character array 'S' of size 6

		scanf("%s", S);  // Read a string of six characters from the standard input and store it in the array 'S'

		for(i = 0; S[i] != '\0'; i++){  // Iterate through each character in the string 'S'
			if(S[i] == 'A' && S[i + 1] == 'C'){  // Check if the current character is 'A' and the next character is 'C'
				printf("Yes\n");  // If so, print 'Yes' to the standard output
				return 0;  // And exit the program
			}
		}

		printf("No\n");  // If no pair of 'AC' is found, print 'No' to the standard output
		return 0;  // End of the main function
	}
}
