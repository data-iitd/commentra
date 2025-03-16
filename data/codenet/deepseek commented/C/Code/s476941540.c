#include <stdio.h>
#include <ctype.h>

int main(){
    int i, alpha[26];
    char ch;

    // Initialize the alpha array to zero for all elements
    for(i = 0; i < 26; i++) alpha[i] = 0;

    // Read characters from the standard input until EOF
    while(1){
        ch = getchar();
        if(ch == EOF) break;

        // Check if the character is an alphabetic character
        if(isalpha(ch)){
            // Increment the corresponding element in alpha based on case
            if(isupper(ch)) alpha[ch - 65]++;
            else alpha[ch - 97]++;
        }
    }

    // Print the counts of each letter from 'a' to 'z'
    ch = 'a';
    for(i = 0; i < 26; i++, ch++){
        printf("%c : %d\n", ch, alpha[i]);
    }
}
