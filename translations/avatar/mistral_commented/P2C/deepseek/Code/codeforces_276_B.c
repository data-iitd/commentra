#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize an empty list 's' to store input elements
    char s[100];
    scanf("%s", s);

    // Initialize an empty dictionary 'dt' to store the count of each unique element
    int dt[256] = {0};

    // Set a boolean variable 'x' to True to indicate whether there is an odd count element in the list
    int x = 1;

    // Iterate through each element 'i' in the list 's'
    for (int i = 0; i < strlen(s); i++) {
        // Increment the count of the current character
        dt[(int)s[i]]++;
    }

    // Initialize a counter 'cnt' to 0 and set 'x' to True
    int cnt = 0;
    x = 1;

    // Iterate through each key-value pair ('key', 'value') in the dictionary 'dt'
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (dt[i] % 2 != 0 && cnt >= 1) {
            x = 0;
            break;
        }
    }

    // After the loop, check the value of 'x'
    if (x) {
        // If it is True, print "First"
        printf("First\n");
    } else if (!x && strlen(s) % 2 == 0) {
        // If it is False and the length of the list 's' is even, print "Second"
        printf("Second\n");
    } else if (!x && strlen(s) % 2 != 0) {
        // If it is False and the length of the list 's' is odd, print "First"
        printf("First\n");
    }

    return 0;
}
