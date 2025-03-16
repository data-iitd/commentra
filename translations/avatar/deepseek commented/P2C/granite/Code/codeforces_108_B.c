

#include <stdio.h>
#include <stdlib.h>

char* s() {
    // Take input from the user
    char* input = malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    // Read the input, split it into a list of integers, and store it in 'a'
    int* a = malloc(100 * sizeof(int));
    int i = 0;
    char* token = strtok(input, " ");
    while (token!= NULL) {
        a[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    // Sort the list 'a'
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (a[k] > a[k + 1]) {
                int temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
    // Iterate through the sorted list starting from the second element
    for (int l = 1; l < i; l++) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[l]!= a[l - 1] && a[l] < a[l - 1] * 2) {
            // If the condition is met, return 'YES'
            char* result = "YES";
            return result;
        }
    }
    // If the loop completes without finding a match, return 'NO'
    char* result = "NO";
    return result;
}

int main() {
    // Print the result returned by the function's()'
    char* result = s();
    printf("%s\n", result);
    return 0;
}
// END-OF-CODE