
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize a new scanner to read input from standard input
    char *input = (char *)malloc(sizeof(char) * 100);
    fgets(input, 100, stdin);

    // Read the first line of input containing 4 integers and store them in ns slice
    printf("Reading input\n");
    int ns[4];
    sscanf(input, "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

    // Sort the ns slice in ascending order
    printf("Sorting the numbers in ns slice\n");
    int i, j, temp;
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (ns[i] > ns[j]) {
                temp = ns[i];
                ns[i] = ns[j];
                ns[j] = temp;
            }
        }
    }

    // Check if the sorted ns slice matches the specific condition (1, 4, 7, 9)
    printf("Checking the condition\n");
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("The condition is true, print YES\n");
        printf("Output: YES\n");
        printf("\n");
        printf("End of the program\n");
        return 0;
    } else {
        printf("The condition is false, print NO\n");
        printf("Output: NO\n");
        printf("\n");
        printf("End of the program\n");
        return 0;
    }
}

