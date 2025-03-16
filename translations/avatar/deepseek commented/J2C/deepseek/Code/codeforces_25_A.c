#include <stdio.h>

int main() {
    int n, array[1001]; // Assuming the maximum number of elements is 1000
    int odd = 0, even = 0, odd_ind = 0, even_ind = 0;

    // Reading the number of elements in the array
    scanf("%d", &n);

    // Populating the array with integers from the user input
    for (int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }

    // Counting the number of odd and even numbers and recording their indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }

    // Comparing the counts of odd and even numbers and printing the index of the majority
    if (odd > even) {
        printf("%d\n", even_ind);
    } else {
        printf("%d\n", odd_ind);
    }

    return 0;
}
