#include <stdio.h>
#include <stdlib.h>

// Define input functions
int* I() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

char* IS() {
    char* str = (char*)malloc(1000 * sizeof(char));
    scanf("%s", str);
    return str;
}

int IN() {
    int num;
    scanf("%d", &num);
    return num;
}

float IF() {
    float num;
    scanf("%f", &num);
    return num;
}

int main() {
    int n = IN();
    int* l = I();

    // Initialize variables
    int f = 1;
    int c = 0;

    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (l[j] > l[j + 1]) {
                int temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
        }
    }

    // Iterate through the array to find the maximum number of unique elements
    for (int i = 0; i < n; i++) {
        if (l[i] > c) {
            c += 1;
        }
    }

    // Print the result
    printf("%d\n", c + 1);

    // Free allocated memory
    free(l);

    return 0;
}
