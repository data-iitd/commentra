#include <stdio.h>
#include <string.h>

int main() {
    char S[100]; // Assuming a maximum length of 100 for the input string
    scanf("%s", S);
    int len = strlen(S);
    
    for (int i = 2; i <= len; i += 2) {
        int half_length = (len - i) / 2;
        if (strncmp(S, S + half_length, half_length) == 0) {
            printf("%d\n", len - i);
            break;
        }
    }
    
    return 0;
}

// <END-OF-CODE>
