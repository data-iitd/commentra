#include <stdio.h>
#include <string.h>

int main() {
    char str[100001]; // Declaring a character array to store the input string
    long k; // Declaring a long integer to store the input long integer

    // Reading a string input from the user
    scanf("%s", str);
    
    // Reading a long integer input from the user
    scanf("%ld", &k);
    
    // Getting the length of the input string
    int n = strlen(str);
    
    // Looping through the first k characters of the character array
    for (int i = 0; i < k; i++) {
        // Checking if the current character is '1'
        if (str[i] == '1') {
            // If it's the last character in the range, print 1 and exit
            if (i == k - 1) {
                printf("1\n");
                return 0; // Exit the program
            }
        } else {
            // If the current character is not '1', print it and exit
            printf("%c\n", str[i]);
            return 0; // Exit the program
        }
    }
}
