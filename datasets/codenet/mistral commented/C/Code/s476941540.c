#include <stdio.h>
#include <ctype.h>

// The main function is the starting point of the program
int main(){
    int i; // Declare an integer variable 'i'
    int alpha[26]; // Declare an integer array 'alpha' of size 26
    char ch; // Declare a character variable 'ch'

    // Initialize all elements of the array 'alpha' to zero
    for(i = 0; i < 26; i++)alpha[i] = 0;

    // Start an infinite loop
    while(1){
        ch = getchar(); // Read a character from the standard input

        // If the character read is End-Of-File (EOF), break the loop
        if(ch == EOF)break;

        // If the character is an alphabetic character
        if(isalpha(ch)){
            // If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
            if(isupper(ch))alpha[ch - 65]++;

            // If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
            else alpha[ch - 97]++;
        }
    }

    // Initialize the character 'ch' with the ASCII value of 'a'
    ch = 'a';

    // Print the count of each alphabetic character and its corresponding ASCII value
    for(i = 0; i < 26; i++, ch++){
        printf("%c : %d\n", ch, alpha[i]);
    }
}
