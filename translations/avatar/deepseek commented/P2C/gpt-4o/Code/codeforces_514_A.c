#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];  // Declare a character array to store the input.
    char st[100] = "";  // Initialize an empty string `st`.
    
    scanf("%s", ip);  // Taking an input from the user and storing it in `ip`.
    
    if (strlen(ip) != 1) {  // Checking if the length of the input `ip` is not equal to 1.
        if (ip[0] == '9') {  // Checking if the first character of `ip` is '9'.
            strcpy(st, "9");  // Assigning "9" to `st`.
            memmove(ip, ip + 1, strlen(ip));  // Removing the first character from `ip`.
        }
        
        for (int i = 0; i < strlen(ip); i++) {  // Iterating over the remaining characters in `ip`.
            int digit = ip[i] - '0';  // Convert character to integer.
            if (digit > 4) {  // Checking if the integer value of the character is greater than 4.
                int n = 9 - digit;  // Calculating the difference between 9 and the integer value.
                char temp[2];  // Temporary string to hold the character.
                sprintf(temp, "%d", n);  // Convert integer to string.
                strcat(st, temp);  // Append to `st`.
            } else {  // If the integer value is not greater than 4.
                strncat(st, &ip[i], 1);  // Simply appending the character to `st`.
            }
        }
    } else {  // If the length of `ip` is 1.
        strcpy(st, ip);  // Assigning `ip` directly to `st`.
    }
    
    printf("%d\n", atoi(st));  // Printing the integer value of `st`.
    
    return 0;
}  // <END-OF-CODE>
