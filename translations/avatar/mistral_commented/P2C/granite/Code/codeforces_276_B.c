
#include <stdio.h>
#include <string.h>

int main() {
    // Initialize an empty string's' to store input elements
    char s[1000];
    scanf("%s", s);

    // Initialize an empty dictionary 'dt' to store the count of each unique element
    int dt[256] = {0};

    // Set a boolean variable 'x' to True to indicate whether there is an odd count element in the string
    int x = 1;

    // Iterate through each character 'i' in the string's'
    for (int i = 0; i < strlen(s); i++) {
        // Convert the character 'i' to its ASCII value and use it as an index in the dictionary 'dt'
        dt[(int)s[i]]++;
    }

    // Initialize a counter 'cnt' to 0 and set 'x' to True
    int cnt = 0;
    x = 1;

    // Iterate through each element 'i' in the dictionary 'dt'
    for (int i = 0; i < 256; i++) {
        // If the value at index 'i' is odd and 'cnt' is less than 1, increment 'cnt' by 1
        if (dt[i] % 2!= 0 && cnt < 1) {
            cnt++;
        }
        // If the value at index 'i' is odd and 'cnt' is already greater than or equal to 1, set 'x' to False and break the loop
        else if (dt[i] % 2!= 0 && cnt >= 1) {
            x = 0;
            break;
        }
    }

    // After the loop, check the value of 'x'
    if (x) {
        // If it is True, print "First"
        printf("First\n");
    }
    else if (!x && strlen(s) % 2 == 0) {
        // If it is False and the length of the string's' is even, print "Second"
        printf("Second\n");
    }
    else if (!x && strlen(s) % 2!= 0) {
        // If it is False and the length of the string's' is odd, print "First"
        printf("First\n");
    }

    return 0;
}
