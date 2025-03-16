#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable S to hold the input string
<<<<<<< HEAD
    char S[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    
=======
    char S[100]; // Assuming the maximum length of the input string is 99 characters

>>>>>>> 98c87cb78a (data updated)
    // Read the input string from the standard input
    scanf("%s", S);
    
    int len = strlen(S);
    
    // Iterate over even lengths of the string from 2 to the length of S
    for (int i = 2; i <= len; i += 2) {
<<<<<<< HEAD
        // Calculate the mid-point
        int mid = (len - i) / 2;
        
        // Check if the first half of the string is equal to the second half
        if (strncmp(S, S[mid:mid + mid], mid) == 0) {
            // If they are equal, print the length of the string minus i
=======
        // Check if the first half of the string (up to the current length minus i)
        // is equal to the second half of the string (from the middle to the current length minus i)
        if (strncmp(S, S + (len - i) / 2, (len - i) / 2) == 0) {
            // If they are equal, print the length of the string minus i
            // This gives the length of the string that is not part of the repeated pattern
>>>>>>> 98c87cb78a (data updated)
            printf("%d\n", len - i);
            // Exit the loop after finding the first match
            break;
        }
    }
<<<<<<< HEAD
    
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
