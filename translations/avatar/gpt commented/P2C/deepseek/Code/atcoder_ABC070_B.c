#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[4];
    char buffer[100];
    char *token;
    int i = 0;

    // Read a line of input
    fgets(buffer, sizeof(buffer), stdin);

    // Split the input into components and convert each component to an integer
    token = strtok(buffer, " ");
    while (token != NULL) {
        A[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print 0
        printf("0\n");
    } else {
        // If the condition is false, sort the array A in ascending order
        for (i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (A[i] > A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
        // Calculate the difference between the largest and the second largest elements in the sorted array and print the result
        printf("%d\n", A[2] - A[1]);
    }

    return 0;
}
