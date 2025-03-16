#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long number, ans = -1, value = 0;
    int mask = 2;
    char s[33];
    
    scanf("%ld", &number);
    
    while (value < number) {
        sprintf(s, "%b", mask++);
        s[0] = '0'; // Remove the first character
        
        int zeros = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                zeros++;
            }
        }
        
        if (zeros != strlen(s) - zeros) {
            continue;
        }
        
        for (int i = 0; s[i] != '\0'; i++) {
            s[i] = (s[i] == '0') ? '4' : '7';
        }
        value = atol(s);
    }
    
    printf("%ld\n", value);
    
    return 0;
}
