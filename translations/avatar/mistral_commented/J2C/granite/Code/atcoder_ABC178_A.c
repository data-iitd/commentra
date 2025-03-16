
#include <stdio.h>

int main() {
    // Reading an integer value from the user input
    int x;
    scanf("%d", &x);

    // Determining a boolean value based on the condition x equals to 1
    int bool = x == 1? 1 : 0;

    // Calculating the result based on the boolean value
    int result =!bool? 1 : 0;

    // Writing the result to the standard output
    printf("%d\n", result);

    // Flushing the output buffer to ensure the output is written immediately
    fflush(stdout);

    return 0;
}
