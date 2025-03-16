#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    
    int even0 = 0, even1 = 0, odd0 = 0, odd1 = 0;
    int length = strlen(s);
    
    // Count characters at even and odd indices
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) { // Even index
            if (s[i] == '0') even0++;
            else if (s[i] == '1') even1++;
        } else { // Odd index
            if (s[i] == '0') odd0++;
            else if (s[i] == '1') odd1++;
        }
    }
    
    // Calculate the two possible replacements
    int option1 = length - (even0 + odd1);
    int option2 = length - (even1 + odd0);
    
    // Print the minimum of the two options
    printf("%d\n", option1 < option2 ? option1 : option2);
    
    return 0;
}

// <END-OF-CODE>
