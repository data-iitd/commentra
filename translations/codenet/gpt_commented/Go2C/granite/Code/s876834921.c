
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold user input
    char s[100];
    
    // Read input from the user
    scanf("%s", s);
    
    // Replace occurrences of "dream" with "D"
    char *ptr = strstr(s, "dream");
    while (ptr!= NULL) {
        ptr[0] = 'D';
        ptr = strstr(ptr + 1, "dream");
    }
    
    // Replace occurrences of "erase" with "E"
    ptr = strstr(s, "erase");
    while (ptr!= NULL) {
        ptr[0] = 'E';
        ptr = strstr(ptr + 1, "erase");
    }
    
    // Remove occurrences of "Der" from the string
    ptr = strstr(s, "Der");
    while (ptr!= NULL) {
        memmove(ptr, ptr + 3, strlen(ptr + 3) + 1);
        ptr = strstr(ptr, "Der");
    }
    
    // Remove occurrences of "Er" from the string
    ptr = strstr(s, "Er");
    while (ptr!= NULL) {
        memmove(ptr, ptr + 2, strlen(ptr + 2) + 1);
        ptr = strstr(ptr, "Er");
    }
    
    // Remove occurrences of "D" from the string
    ptr = strstr(s, "D");
    while (ptr!= NULL) {
        memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        ptr = strstr(ptr, "D");
    }
    
    // Remove occurrences of "E" from the string
    ptr = strstr(s, "E");
    while (ptr!= NULL) {
        memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        ptr = strstr(ptr, "E");
    }
    
    // Trim any leading or trailing whitespace from the string
    char *start = s;
    while (*start!= '\0' && isspace(*start)) {
        start++;
    }
    char *end = s + strlen(s) - 1;
    while (end >= start && isspace(*end)) {
        end--;
    }
    end[1] = '\0';
    memmove(s, start, end - start + 2);
    
    // Check if the resulting string is empty
    if (strlen(s) == 0) {
        // If the string is empty, print "YES"
        printf("YES\n");
    } else {
        // If the string is not empty, print "NO"
        printf("NO\n");
    }
    
    return 0;
}
