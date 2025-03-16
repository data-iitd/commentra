#include <iostream>
#include <cctype>

int main(){
    int i, alpha[26] = {0};
    char ch;

    // Read characters from the standard input until EOF
    while(true){
        ch = std::cin.get();
        if(ch == EOF) break;

        // Check if the character is an alphabetic character
        if(std::isalpha(ch)){
            // Increment the corresponding element in alpha based on case
            if(std::isupper(ch)) alpha[ch - 65]++;
            else alpha[ch - 97]++;
        }
    }

    // Print the counts of each letter from 'a' to 'z'
    ch = 'a';
    for(i = 0; i < 26; i++, ch++){
        std::cout << ch << " : " << alpha[i] << std::endl;
    }
}
