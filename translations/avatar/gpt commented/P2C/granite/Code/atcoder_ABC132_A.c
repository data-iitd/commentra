
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Take input string from the user
    char S[100001];
    scanf("%s", S);

    // Create an array to store the frequency of each character in the string
    int count[256] = {0};

    // Iterate over each character in the input string
    for (int i = 0; S[i]!= '\0'; i++) {
        // Increment the count of the current character
        count[S[i]]++;
    }

    // Create a set to store the unique characters from the input string
    int unique = 0;
    for (int i = 0; i < 256; i++) {
        // If the count of the current character is not equal to 0
        if (count[i]!= 0) {
            // Increment the count of unique characters
            unique++;
        }
    }

    // Check if the number of unique characters is not equal to 2
    if (unique!= 2) {
        // If there are not exactly 2 unique characters, print "No" and exit
        printf("No\n");
        return 0;
    }

    // Iterate over each unique character in the set
    for (int i = 0; i < 256; i++) {
        // If the count of the current character is not equal to 2
        if (count[i]!= 2) {
            // If any character does not appear exactly twice, print "No" and exit
            printf("No\n");
            return 0;
        }
    }

    // If both conditions are satisfied, print "Yes"
    printf("Yes\n");

    return 0;
}
