#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare a character array 's' to store the input string
    char s[1000];
    
    // Read the input string from the user
    scanf("%s", s);
    
    // Calculate the length of the string 's'
    int len = strlen(s);
    
    // Declare two integer arrays 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the string 's' respectively
    int even[2] = {0};
    int odd[2] = {0};
    
    // Count the frequency of '0' and '1' in the first half of the string 's'
    for (int i = 0; i < len / 2; i++) {
        if (s[i] == '0') {
            even[0]++;
        } else {
            even[1]++;
        }
    }
    
    // Count the frequency of '0' and '1' in the second half of the string 's'
    for (int i = len / 2; i < len; i++) {
        if (s[i] == '0') {
            odd[0]++;
        } else {
            odd[1]++;
        }
    }
    
    // Calculate the minimum difference between the length of the string 's' and the sum of the frequencies of '0' and '1' in either half of the string
    int result = len - (even[0] + odd[1]);
    if (len - (even[1] + odd[0]) < result) {
        result = len - (even[1] + odd[0]);
    }
    
    // Print the result
    printf("%d\n", result);
    
    return 0;
}
