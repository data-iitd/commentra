
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char s[100];
    
    // Read input from the user and store it in the variable's'
    scanf("%s", s);
    
    // Check if the length of the string is at least 4 characters 
    // and if the first four characters are "YAKI"
    if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
        // If the condition is true, print "Yes"
        printf("Yes\n");
    } else {
        // If the condition is false, print "No"
        printf("No\n");
    }
    
    return 0;
}
