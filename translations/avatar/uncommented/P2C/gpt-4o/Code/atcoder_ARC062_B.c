#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    
    int num_g = 0, num_p = 0, score = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        char x = s[i];
        if (x == 'g') {
            if (num_g - num_p > 0) {
                score += 1;
                num_p += 1;
            } else {
                // score remains the same
                num_g += 1;
            }
        } else if (x == 'p') {
            if (num_g - num_p > 0) {
                // score remains the same
                num_p += 1;
            } else {
                score -= 1;
                num_g += 1;
            }
        }
    }
    
    printf("%d\n", score);
    return 0;
}

// <END-OF-CODE>
