

#include <stdio.h>

int main() {
    int a[100];  // Declare an array of integers
    int n;  // Declare a variable to store the number of elements
    printf("Enter the number of elements: ");  // Prompt the user to enter the number of elements
    scanf("%d", &n);  // Read the number of elements from the user
    printf("Enter the elements: ");  // Prompt the user to enter the elements
    for (int i = 0; i < n; i++) {  // Iterate over the array, reading each element
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {  // Iterate over the array again, checking each element
        if (a[i] == 0) {  // If an element is 0
            printf("Position of 0: %d\n", i + 1);  // Print the position (1-indexed) of that element and break the loop
            break;
        }
    }
    return 0;
}

