#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function named 'run' that takes two arguments 's' and 't'
void run(char *s, char *t) {
    // Using Counter function to count the occurrences of each character in string 's'
    // and storing the result in a dictionary
    int ss[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        ss[s[i] - 'a']++;
    }

    // Using Counter function to count the occurrences of each character in string 't'
    // and storing the result in a dictionary
    int tt[26] = {0};
    for (int i = 0; i < strlen(t); i++) {
        tt[t[i] - 'a']++;
    }

    // Comparing the sorted lists of occurrences of characters in strings 's' and 't'
    // If they are equal, then the strings have the same frequency distribution of characters
    // and thus are identical, so return 'Yes'
    // Otherwise, return 'No'
    int i = 0;
    while (i < 26) {
        if (ss[i] != tt[i]) {
            printf("No\n");
            return;
        }
        i++;
    }
    printf("Yes\n");
}

// Define a function named 'main' that takes no arguments
int main() {
    // Taking input strings 's' and 't' from the user
    char s[1000000], t[1000000];
    scanf("%s %s", s, t);

    // Calling the 'run' function with strings 's' and 't' as arguments and printing the result
    run(s, t);

    return 0;
}

