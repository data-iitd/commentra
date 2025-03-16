#include <stdio.h>  // Include stdio.h for input and output functions
#include <string.h> // Include string.h for string manipulation functions

int main(){
    char c[11], ans[11] = {'\0'}; // Declare character arrays c and ans
    scanf("%s", c); // Read input string into c

    // Process the input string
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] != 'B')
            ans[strlen(ans)] = c[i]; // Append character to ans if not 'B'
        else
            ans[strlen(ans) - 1] = '\0'; // Remove last character from ans if 'B'
    }

    printf("%s\n", ans); // Output the result string ans
}
