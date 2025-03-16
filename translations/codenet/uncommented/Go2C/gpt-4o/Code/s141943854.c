#include <stdio.h>
#include <stdlib.h>

void check(int condition) {
    if (condition) {
        fprintf(stderr, "error: invalid input\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char sage[10];
    fgets(sage, sizeof(sage), stdin);

    // Remove newline character from input
    sage[strcspn(sage, "\n")] = 0;

    if (strcmp(sage, "1") == 0) {
        printf("Hello World\n");
    } else if (strcmp(sage, "2") == 0) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            char input[10];
            fgets(input, sizeof(input), stdin);
            int num = atoi(input);
            check(num == 0 && input[0] != '0'); // Check for invalid input
            sum += num;
        }
        printf("%d\n", sum);
    }

    return 0;
}

// <END-OF-CODE>
