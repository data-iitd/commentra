
#include <stdio.h>
#include <string.h>

// Declare variables
char c[11]; // An array to store the input string
char ans[11] = {'\0'}; // An array to store the output string

int main(){
    // Initialize variables
    scanf("%s",c); // Read a string from the standard input and store it in the 'c' array

    // Process the string
    for(int i=0;c[i]!='\0';i++){ // Iterate through each character in the string 'c'
        if(c[i]!='B'){ // If the current character is not 'B'
            ans[strlen(ans)] = c[i]; // Append the character to the output string 'ans'
        }
        else{ // If the current character is 'B'
            ans[strlen(ans)-1]='\0'; // Remove the last character from the output string 'ans'
        }
    }

    // Print the output
    printf("%s\n",ans); // Print the final output string
}

// The comments explain the purpose of each logical block and make the code more readable.