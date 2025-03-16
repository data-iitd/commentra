#include <stdio.h>
#include <string.h>

int main() {
    char n[100];
    char a[][6] = {"10", "100", "1000", "10000", "100000"};
    
    // Read input from the user
    scanf("%s", n);
    
    // Convert the input string into a list of integers and calculate the sum
    int new = 0;
    for (int i = 0; i < strlen(n); i++) {
        new += n[i] - '0';
    }
    
    // Check if the input is one of the predefined values in the list 'a'
    int is_in_a = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            is_in_a = 1;
            break;
        }
    }
    
    // If the input matches one of the predefined values, print 10
    if (is_in_a) {
        printf("10\n");
    } else {
        // If the input does not match, print the calculated sum
        printf("%d\n", new);
    }
    
    return 0;
}
