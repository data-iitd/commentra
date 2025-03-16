
#include <stdio.h>
#include <string.h>

int main() {
    // Read the input string
    char s[100];
    scanf("%s", s);
    
    // Check if the string contains both 'A' and 'B'
    if (strstr(s, "A") && strstr(s, "B")) {
        // If both characters are present, print "Yes"
        printf("Yes\n");
    } else {
        // If either character is missing, print "No"
        printf("No\n");
    }
    
    return 0;
}
