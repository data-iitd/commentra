

#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];  // Declaring a character array `ip` with a maximum length of 100.
    char st[100];  // Declaring a character array `st` with a maximum length of 100.
    scanf("%s", ip);  // Taking an input from the user and storing it in the character array `ip`.
    int len = strlen(ip);  // Getting the length of the input `ip`.
    int i;  // Declaring an integer variable `i`.
    if (len!= 1) {  // Checking if the length of `ip` is not equal to 1.
        if (ip[0] == '9') {  // Checking if the first character of `ip` is "9".
            st[0] = '9';  // Assigning "9" to the first character of `st`.
            strcpy(ip + 1, st);  // Copying the remaining characters of `ip` to `st`.
        }
        for (i = 0; i < len; i++) {  // Iterating over the characters in `ip`.
            if (ip[i] - '0' > 4) {  // Checking if the integer value of the character is greater than 4.
                st[i] = '9' - (ip[i] - '0');  // Calculating the difference between 9 and the integer value and assigning it to `st`.
            } else {  // If the integer value is not greater than 4.
                st[i] = ip[i];  // Simply assigning the character to `st`.
            }
        }
    } else {  // If the length of `ip` is 1.
        strcpy(st, ip);  // Assigning `ip` directly to `st`.
    }
    printf("%d", atoi(st));  // Printing the integer value of `st`.
    return 0;
}
// END-OF-CODE