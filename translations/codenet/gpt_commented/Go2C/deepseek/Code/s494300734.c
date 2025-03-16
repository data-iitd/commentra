#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char s[100];
    
    // Read a string input from the user
    scanf("%s", s);
    
    // Initialize the answer variable with "No"
    char ans[] = "No";
    
    // Check if the first occurrence of 'C' is before the last occurrence of 'F'
    int firstC = -1;
    int lastF = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'C') {
            firstC = i;
            break;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == 'F') {
            lastF = i;
            break;
        }
    }
    
    if (firstC != -1 && lastF != -1 && firstC < lastF) {
        // If true, set the answer to "Yes"
        strcpy(ans, "Yes");
    }
    
    // Print the final answer
    printf("%s\n", ans);
    
    return 0;
}
