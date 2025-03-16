

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    fgets(input, 100, stdin); // Read input from standard input
    char *sage = input;

    if (strcmp(sage, "1\n") == 0) {
        printf("Hello World\n"); // Print "Hello World" if input is "1"
    } else if (strcmp(sage, "2\n") == 0) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            fgets(input, 100, stdin); // Read input from standard input
            char *num_str = input;
            int num = atoi(num_str); // Convert string to integer
            sum += num; // Add the integer to the sum
        }
        printf("%d\n", sum); // Print the sum of the two integers
    }

    return 0;
}

