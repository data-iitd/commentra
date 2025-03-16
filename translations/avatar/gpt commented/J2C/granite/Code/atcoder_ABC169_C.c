
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the user
    char a[20];
    char b[20];
    scanf("%s %s", a, b);

    // Convert the string to a character array for processing
    int length = strlen(b);
    char bChar[length];
    for (int i = 0; i < length; i++) {
        if (b[i]!= '.') {
            bChar[i] = b[i];
        }
    }

    // Convert the built string (bStr) to an integer
    int bInt = atoi(bChar);

    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    long result = (atol(a) * bInt) / 100;

    // Print the result to the console
    printf("%ld\n", result);

    return 0;
}
