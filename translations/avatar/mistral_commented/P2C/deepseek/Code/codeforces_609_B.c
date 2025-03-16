#include <stdio.h>
#include <stdlib.h>

// Function to read input as a list of integers
int* _input() {
    int* arr = (int*)malloc(10000 * sizeof(int)); // Assuming the input size won't exceed 10000
    char ch;
    int i = 0;
    while (scanf("%d%c", &arr[i], &ch) == 2) {
        if (ch == '\n') break;
        i++;
    }
    return arr;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* lst = _input();
    int l[10000] = {0}; // Assuming the input size won't exceed 10000

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the current element is not already present in the dictionary 'l'
        if (l[lst[i]] == 0) {
            // Add the current element to the dictionary 'l' with a frequency of 1
            l[lst[i]] = 1;
        } else {
            // Increment the frequency of the current element in the dictionary 'l'
            l[lst[i]]++;
        }
    }

    // Initialize result variable 'res' to 0
    int res = 0;

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the frequency of the current element in the dictionary 'l' is greater than 1
        if (l[lst[i]] > 1) {
            // Calculate the number of elements that have a smaller frequency than the current element
            // and add it to the result variable 'res'
            res += n - i - l[lst[i]];
            // Decrease the frequency of the current element in the dictionary 'l' by 1
            l[lst[i]]--;
        } else {
            // Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
            res += n - i - 1;
        }
    }

    // Print the final result
    printf("%d\n", res);

    free(lst); // Free the allocated memory
    return 0;
}
