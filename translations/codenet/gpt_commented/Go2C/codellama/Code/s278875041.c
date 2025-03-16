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
    int i = 0;
    while (tmp[i] != '\0') {
        if (tmp[i] == '1') {
            tmp[i] = '0';
        }
        i++;
    }
    
    // Replace all occurrences of '9' with '1' in the modified string
    char b[100];
    strcpy(b, tmp);
    i = 0;
    while (b[i] != '\0') {
        if (b[i] == '9') {
            b[i] = '1';
        }
        i++;
    }
    
    // Replace all occurrences of '0' with '9' in the second modified string
    char ans[100];
    strcpy(ans, b);
    i = 0;
    while (ans[i] != '\0') {
        if (ans[i] == '0') {
            ans[i] = '9';
        }
        i++;
    }
    
    // Print the final transformed string
    printf("%s\n", ans);
    
    return 0;
}
