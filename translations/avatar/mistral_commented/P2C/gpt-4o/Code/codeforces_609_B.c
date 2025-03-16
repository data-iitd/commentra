#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Function to read input as a list of integers
void read_input(int *arr, int *n, int *m) {
    scanf("%d %d", n, m);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n, m;
    int lst[MAX_SIZE];
    int frequency[MAX_SIZE] = {0}; // Frequency array to store the count of each element
    long long res = 0; // Result variable

    // Read number of elements 'n' and size 'm' of the list 'lst'
    read_input(lst, &n, &m);

    // Initialize frequency of each element in the list
    for (int i = 0; i < n; i++) {
        frequency[lst[i]]++;
    }

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the frequency of the current element is greater than 1
        if (frequency[lst[i]] > 1) {
            // Calculate the number of elements that have a smaller frequency than the current element
            res += n - i - frequency[lst[i]];
            // Decrease the frequency of the current element by 1
            frequency[lst[i]]--;
        } else {
            // If the frequency is equal to 1
            res += n - i - 1;
        }
    }

    // Print the final result
    printf("%lld\n", res);

    return 0;
}

// <END-OF-CODE>
