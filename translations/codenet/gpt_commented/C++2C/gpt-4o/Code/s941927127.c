#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

<<<<<<< HEAD
int main(void) {
=======
int main(void)
{
>>>>>>> 98c87cb78a (data updated)
    // Declare a string variable to hold the input
    char W[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    
    // Read input string from the user
    scanf("%s", W);
    
    // Get the length of the string
    int len = strlen(W);
    
    // Sort the characters in the string in ascending order
    qsort(W, len, sizeof(char), compare);

    // Iterate through the sorted string, checking pairs of characters
<<<<<<< HEAD
    for (int i = 0; i < len; i += 2) {
        // Check if the current character is not equal to the next character
        if (i + 1 < len && W[i] != W[i + 1]) {
=======
    for (int i = 0; i < len; i += 2)
    {
        // Check if the current character is not equal to the next character
        if (i + 1 < len && W[i] != W[i + 1])
        {
>>>>>>> 98c87cb78a (data updated)
            // If they are not equal, print "No" and exit the program
            printf("No\n");
            return 0;
        }
    }
    
    // If all pairs are equal, print "Yes"
    printf("Yes\n");

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
