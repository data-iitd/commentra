
#include <stdio.h>

// Function to read input as a list of integers
void _input (int *lst, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
}

// Read number of elements 'n' and size'm' of the list 'lst'
int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an empty dictionary 'l' to store the frequency of each element
    int lst[n];
    _input(lst, n);
    int l[m];
    for (int i = 0; i < m; i++) {
        l[i] = 0;
    }

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the current element is not already present in the dictionary 'l'
        if (l[lst[i]] == 0) {
            // Add the current element to the dictionary 'l' with a frequency of 1
            l[lst[i]] = 1;
        }
        // If the current element is already present in the dictionary 'l'
        else {
            // Increment the frequency of the current element in the dictionary 'l'
            l[lst[i]] += 1;
        }
    }

    // Initialize result variable'res' to 0
    int res = 0;

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the frequency of the current element in the dictionary 'l' is greater than 1
        if (l[lst[i]] > 1) {
            // Calculate the number of elements that have a smaller frequency than the current element
            // and add it to the result variable'res'
            res += n - i - l[lst[i]];
            // Decrease the frequency of the current element in the dictionary 'l' by 1
            l[lst[i]] -= 1;
        }
        // If the frequency of the current element in the dictionary 'l' is equal to 1
        else {
            // Calculate the number of elements that have not been processed yet and add it to the result variable'res'
            res += n - i - 1;
        }
    }

    // Print the final result
    printf("%d\n", res);

    return 0;
}
