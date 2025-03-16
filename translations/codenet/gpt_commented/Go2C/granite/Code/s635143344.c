
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create an array to hold three integers
    int in[3];

    // Read three integers from standard input
    for (int i = 0; i < 3; i++) {
        scanf("%d", &in[i]);
    }

    // Sort the integers in ascending order
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (in[i] > in[j]) {
                int temp = in[i];
                in[i] = in[j];
                in[j] = temp;
            }
        }
    }

    // Calculate the result based on the sorted integers
    // The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
    int result = in[2] * 10 + in[1] + in[0];

    // Print the result
    printf("%d\n", result);

    return 0;
}
