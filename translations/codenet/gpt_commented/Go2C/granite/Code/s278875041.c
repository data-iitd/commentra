
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char a[100];
    
    // Read input from the user and store it in variable 'a'
    scanf("%s", a);
    
    // Replace all occurrences of '1' with '0' in the input string
    char tmp[100];
    strcpy(tmp, a);
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '1') {
            tmp[i] = '0';
        }
    }
    
    // Replace all occurrences of '9' with '1' in the modified string
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '9') {
            tmp[i] = '1';
        }
    }
    
    // Replace all occurrences of '0' with '9' in the second modified string
    char ans[100];
    strcpy(ans, tmp);
    for (int i = 0; i < strlen(ans); i++) {
        if (ans[i] == '0') {
            ans[i] = '9';
        }
    }
    
    // Print the final transformed string
    printf("%s\n", ans);
    
    return 0;
}
