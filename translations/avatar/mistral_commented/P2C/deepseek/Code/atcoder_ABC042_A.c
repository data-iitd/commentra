#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int numbers[100];
    int count = 0;

    // Read user input
    fgets(input, sizeof(input), stdin);

    // Split the input by space and convert to integers
    char *token = strtok(input, " ");
    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Check if the array contains exactly 2 occurrences of the integer 5
    int five_count = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] == 5) {
            five_count++;
        }
    }

    if (five_count == 2) {
        // Calculate the sum of all elements in the array
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += numbers[i];
        }

        // Check if the sum equals 17
        if (sum == 17) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
