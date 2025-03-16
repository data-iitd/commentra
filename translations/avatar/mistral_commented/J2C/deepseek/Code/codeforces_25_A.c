#include <stdio.h>

int main() {
    int n, array[1000], odd = 0, even = 0, odd_ind = 0, even_ind = 0;

    // Reading the number of elements in the array from user input
    scanf("%d", &n);

    // Reading the elements of the array from user input
    for (int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }

    // Counting the number of odd and even elements and storing their indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {  // If the current element is even
            even++;  // Increment the count of even elements
            even_ind = i;  // Store the index of the current even element
        } else {  // If the current element is odd
            odd++;  // Increment the count of odd elements
            odd_ind = i;  // Store the index of the current odd element
        }
    }

    // Determining the output based on the count of odd and even elements
    if (odd > even) {  // If there are more odd elements than even elements
        printf("%d\n", even_ind);  // Print the index of the last even element
    } else {  // If there are more even elements than odd elements
        printf("%d\n", odd_ind);  // Print the index of the last odd element
    }

