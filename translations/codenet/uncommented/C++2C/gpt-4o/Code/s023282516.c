#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *divide[4] = {"dream", "dreamer", "erase", "eraser"};

<<<<<<< HEAD
int main() {
    char S[100]; // Assuming the maximum length of S is 100
    scanf("%s", S);

    // Reverse the string S
    int len = strlen(S);
    for (int i = 0; i < len / 2; i++) {
        char temp = S[i];
        S[i] = S[len - i - 1];
        S[len - i - 1] = temp;
    }

    // Reverse the divide strings
    for (int i = 0; i < 4; i++) {
        int d_len = strlen(divide[i]);
        for (int j = 0; j < d_len / 2; j++) {
            char temp = divide[i][j];
            divide[i][j] = divide[i][d_len - j - 1];
            divide[i][d_len - j - 1] = temp;
        }
=======
void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char S[100]; // Assuming the maximum length of S is 99 characters
    scanf("%s", S);

    // Reverse the input string
    reverse_string(S);
    for (int i = 0; i < 4; ++i) {
        reverse_string(divide[i]);
>>>>>>> 98c87cb78a (data updated)
    }

    // Check if we can divide the string
    bool can = true;
<<<<<<< HEAD
    for (int i = 0; i < len;) {
        bool can2 = false; // Can we divide with any of the 4 strings
        for (int j = 0; j < 4; j++) {
            int d_len = strlen(divide[j]);
            if (strncmp(S + i, divide[j], d_len) == 0) { // Check if we can divide with d
                can2 = true;
                i += d_len; // Move i forward if we can divide
=======
    for (int i = 0; i < strlen(S);) {
        bool can2 = false; // Check if we can divide with any of the strings
        for (int j = 0; j < 4; ++j) {
            char *d = divide[j];
            int d_len = strlen(d);
            if (strncmp(S + i, d, d_len) == 0) { // Check if we can divide with d
                can2 = true;
                i += d_len; // Move i forward
>>>>>>> 98c87cb78a (data updated)
                break; // Break to avoid checking other strings after a successful match
            }
        }
        if (!can2) { // If we couldn't divide
            can = false;
            break;
        }
    }

    if (can) printf("YES\n");
    else printf("NO\n");

    return 0;
}

// <END-OF-CODE>
