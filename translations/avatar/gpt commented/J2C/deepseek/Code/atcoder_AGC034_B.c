#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    long cnt = 0, tmp = 0;
    
    // Read the input string
    scanf("%s", s);
    
    // Length of the string
    int len = strlen(s);
    
    // Iterate through the string
    for (int i = 0; i < len; i++) {
        // Increment temporary counter for 'A'
        if (s[i] == 'A') {
            tmp++;
        }
        // Add the count of 'A's to the result when 'D' is encountered
        else if (s[i] == 'D') {
            cnt += tmp;
        }
        // Reset the temporary counter for any other character
        else {
            tmp = 0;
        }
    }
    
    // Output the final count of valid pairs
    printf("%ld\n", cnt);
    
    return 0;
}
