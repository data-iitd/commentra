#include <stdio.h>
#include <stdlib.h>

int main(){
	// Declare an integer variable to be used as a loop counter
	int i;
	
	// Declare a character array to store the input string
	char S[6];
	
	// Read a string input from the user and store it in S
	scanf("%s", S);
	
	// Loop through each character in the string S
	for(i = 0; S[i] != '\0'; i++){
		// Check if the current character is 'A' and the next character is 'C'
		if(S[i] == 'A' && S[i + 1] == 'C'){
			// If the condition is met, print "Yes" and exit the program
			printf("Yes\n");
			return 0;
		}
	}
	
	// If the condition is not met after the loop completes, print "No" and exit the program
	printf("No\n");
	return 0;
}
