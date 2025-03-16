#include <stdio.h> // Include the necessary header files for input and output operations

char str[100]; // Declare a character array (string) variable named str with a maximum length of 100 characters

int main() { // The main function is the entry point of the program
  	scanf("%s", str); // Input the string from the user and store it in the character array variable str
  	if (str[2] == str[3] && str[4] == str[5]) printf("Yes\n"); // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
  	else printf("No\n"); // If the conditions are not met, output "No"
}

