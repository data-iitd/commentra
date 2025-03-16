
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];  // Declare a character array to store the input string
    scanf("%s", s);  // Read the input string and store it in the character array

    int dt[256] = {0};  // Initialize an array to store the frequency count of each character
    int x = 1;  // Initialize a boolean variable to track the result
    int cnt = 0;  // Initialize a counter to keep track of characters with an odd frequency

    // Iterate over each character in the input string and update the frequency count in the array
    for (int i = 0; i < strlen(s); i++) {
        dt[(int)s[i]]++;
    }

    // Iterate over the array to determine if there is more than one character with an odd frequency
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2!= 0 && cnt < 1) {
            cnt++;
        } else if (dt[i] % 2!= 0 && cnt >= 1) {
            x = 0;
            break;
        }
    }

    // Determine the output based on the value of cnt and the length of the input string
    if (x) {
        printf("First\n");  // Print "First" if there is at most one character with an odd frequency
    } else if (!x && strlen(s) % 2 == 0) {
        printf("Second\n");  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
    } else if (!x && strlen(s) % 2!= 0) {
        printf("First\n");  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
    }

    return 0;
}
