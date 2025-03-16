#include <stdio.h> // Include the stdio.h library for input and output operations
#include <string.h> // Include the string.h library for string manipulation

int main() {
    char s[100], t[100]; // Declare two character arrays, s and t, with a maximum size of 100
    scanf("%s %s", s, t); // Read input strings s and t from the user

    // Create a new string to hold the doubled version of s
<<<<<<< HEAD
    char doubled_s[200]; // Maximum size is 200 to hold the doubled string
    strcpy(doubled_s, s); // Copy s into doubled_s
    strcat(doubled_s, s); // Concatenate s to itself

    // Check if string t can be found within the doubled string s
    // If found, print "Yes", otherwise print "No"
    if (strstr(doubled_s, t) != NULL) {
=======
    char doubled[200]; // Since s can be at most 100, doubled can hold 200 characters
    strcpy(doubled, s); // Copy s into doubled
    strcat(doubled, s); // Concatenate s with itself

    // Check if string t can be found within the doubled string s
    // If found, print "Yes", otherwise print "No"
    if (strstr(doubled, t) != NULL) {
>>>>>>> 98c87cb78a (data updated)
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
