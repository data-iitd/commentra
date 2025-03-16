#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] == s[len - 1 - i]) continue;
        else return false;
    }
    return true;
}

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
<<<<<<< HEAD
    
    int len = strlen(s);
    char firstHalf[100]; // Buffer for the first half of the string
    strncpy(firstHalf, s, len / 2);
    firstHalf[len / 2] = '\0'; // Null-terminate the first half string
=======
    int len = strlen(s);
    char firstHalf[100]; // Buffer for the first half of the string
    strncpy(firstHalf, s, len / 2);
    firstHalf[len / 2] = '\0'; // Null-terminate the first half
>>>>>>> 98c87cb78a (data updated)

    if (isPalindrome(s) && isPalindrome(firstHalf)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
<<<<<<< HEAD
    
=======
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
