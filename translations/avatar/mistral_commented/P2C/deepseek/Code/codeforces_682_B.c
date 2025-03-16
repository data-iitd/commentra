#include <stdio.h>
#include <stdlib.h>

// Function to read a list of integers from standard input
int* read_ints() {
    int buffer_size = 100;
    int* buffer = (int*)malloc(buffer_size * sizeof(int));
    int* array = (int*)malloc(buffer_size * sizeof(int));
    int count = 0;
    int num;

    while (scanf("%d", &num) != EOF) {
        if (count >= buffer_size) {
            buffer_size *= 2;
            buffer = (int*)realloc(buffer, buffer_size * sizeof(int));
        }
        buffer[count++] = num;
    }

    for (int i = 0; i < count; i++) {
        array[i] = buffer[i];
    }

    free(buffer);
    return array;
}

// Function to read an integer from standard input
int read_int() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to sort an array of integers in ascending order
void sort_ints(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Read the number of test cases 'n'
    int n = read_int();

    // Read the list 'l' of length 'n' containing 'n' integers
    int* l = read_ints();

    // Initialize variable 'f' to 1
    int f = 1;

    // Sort the list 'l' in ascending order
    sort_ints(l, n);

    // Initialize variable 'c' to 0
    int c = 0;

    // Iterate through the list 'l'
    for (int i = 0; i < n; i++) {
        // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
        if (l[i] > c) {
            c += 1;
        }
    }

    // Print the final result, which is the number of unique elements in the list 'l' plus 1
    printf("%d\n", c + 1);

    // Free the allocated memory for the list 'l'
    free(l);

    return 0;
}
