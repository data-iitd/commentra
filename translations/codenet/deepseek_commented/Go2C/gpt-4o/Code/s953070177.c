#include <stdio.h>
#include <stdlib.h>
#include <math.h>

<<<<<<< HEAD
#define MAX_SIZE 500001

// Function to read the next integer from the input.
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
=======
// Function to read the next integer from the input.
int getNextInt() {
    int value;
    scanf("%d", &value);
>>>>>>> 98c87cb78a (data updated)
    return value;
}

// Function to calculate the absolute value of an integer.
int absint(int a) {
    return a < 0 ? -a : a;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
<<<<<<< HEAD
=======

    // Check if a file name is provided as an argument.
>>>>>>> 98c87cb78a (data updated)
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the number of elements.
<<<<<<< HEAD
    int n = getNextInt(fp);

    // Initialize an array to store the elements and a sum variable.
    int aa[MAX_SIZE] = {0};
=======
    int n = getNextInt();

    // Initialize an array to store the elements and a sum variable.
    int *aa = (int *)malloc((n + 2) * sizeof(int));
>>>>>>> 98c87cb78a (data updated)
    int sum = 0;

    // Read the elements into the array and calculate the sum of absolute differences.
    for (int i = 0; i < n; i++) {
<<<<<<< HEAD
        aa[i + 1] = getNextInt(fp);
=======
        aa[i + 1] = getNextInt();
>>>>>>> 98c87cb78a (data updated)
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    // Calculate and print the differences for each element.
<<<<<<< HEAD
    for (int i = 1; i <= n; i++) {
=======
    for (int i = 1; i < n + 1; i++) {
>>>>>>> 98c87cb78a (data updated)
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        printf("%d\n", ans);
    }

<<<<<<< HEAD
=======
    // Free the allocated memory.
    free(aa);

    // Close the file if it was opened.
>>>>>>> 98c87cb78a (data updated)
    if (fp != stdin) {
        fclose(fp);
    }

<<<<<<< HEAD
    return EXIT_SUCCESS;
=======
    return 0;
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
