

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100001];  // Declare a character array S with a maximum length of 100000
    scanf("%s", S);  // Take a string input from the user and store it in the array S
    int c[256] = {0};  // Declare an integer array c of size 256 to store the frequency of each character
    int i;
    for (i = 0; S[i]!= '\0'; i++) {  // Iterate over the string S and count the frequency of each character
        c[S[i]]++;
    }
    int Sa[256] = {0};  // Declare an integer array Sa of size 256 to store the unique characters
    int j = 0;
    for (i = 0; i < 256; i++) {  // Iterate over the array c and store the unique characters in the array Sa
        if (c[i]!= 0) {
            Sa[j] = i;
            j++;
        }
    }
    if (j!= 2) {  // Check if the number of unique characters is not equal to 2
        printf("No\n");  // Print "No" and exit if the condition is true
        return 0;  // Exit the program
    }
    for (i = 0; i < j; i++) {  // Iterate over the array Sa and check if the frequency of each character is not equal to 2
        if (c[Sa[i]]!= 2) {
            printf("No\n");  // Print "No" and exit if the condition is true
            return 0;  // Exit the program
        }
    }
    printf("Yes\n");  // Print "Yes" if all characters have a frequency of 2
    return 0;  // Return 0 to indicate successful execution
}

