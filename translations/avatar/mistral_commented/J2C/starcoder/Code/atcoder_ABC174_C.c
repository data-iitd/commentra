
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaring static variables for input and output
    static char input[100000];
    static char output[100000];

    // Reading the input value of K
    scanf("%s", input);

    // Checking if K is even or multiple of 5, returning -1 if true
    if (input[0] == '0' || (input[0] - '0') % 2 == 0 || (input[0] - '0') % 5 == 0) {
        sprintf(output, "-1");
    } else {
        // If K is multiple of 7, dividing it by 7 and multiplying it by 9
        if (input[0] - '0' % 7 == 0) {
            input[0] = '0';
        }
        input[0] = (input[0] - '0') / 7 * 9 + '0';

        // Initializing the answer variable and the remainder variable
        int ans = 1, remainder = 10 % (input[0] - '0');

        // Using a while loop to find the answer
        while (remainder!= 1) {
            ans++; // Incrementing the answer variable
            remainder = remainder * 10 % (input[0] - '0'); // Updating the remainder variable
        }

        // Returning the answer
        sprintf(output, "%d", ans);
    }

    // Printing the answer
    printf("%s", output);

    return 0;
}

