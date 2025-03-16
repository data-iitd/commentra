
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Function to sort the vector in ascending order using insertion sort algorithm
void sort(int* a_parrIntValue, int a_iNum);
 
int main(void) {
 
    int iNum = 0; // Initialize a variable to store the number of elements in the vector
    scanf("%d", &iNum); // Read the number of elements from the standard input
 
    int* parrIntValue = (int*)malloc(iNum * sizeof(int)); // Allocate memory for the vector
    while (iNum) {
        int iIntValue = 0; // Initialize a variable to store the next integer to be added to the vector
        scanf("%d", &iIntValue); // Read the next integer from the standard input
        parrIntValue[iNum-1] = iIntValue; // Add the integer to the vector
        iNum--; // Decrement the counter
    }
 
    // Call the sorting function to sort the vector
    sort(parrIntValue, iNum);
 
    return 0;
}
 
void sort(int* a_parrIntValue, int a_iNum) {
 
    // Iterate through each element in the vector starting from the second element
    for (int i = 0; i < a_iNum; i++) {
        if (i!= 0) { // Check if we are not at the first element
 
            int iIntValue = a_parrIntValue[i]; // Get the value of the current element
            int j = i - 1; // Initialize a variable to store the index of the previous element
            while ((j >= 0) && (a_parrIntValue[j] > iIntValue)) { // While the previous element is greater than the current element
                a_parrIntValue[j+1] = a_parrIntValue[j]; // Swap the previous and next elements
                j--; // Decrement the index of the previous element
            }
            a_parrIntValue[j+1] = iIntValue; // Place the current element at its correct position
        }
 
        // Print the sorted vector after each insertion
        for (int k = 0; k < a_iNum; k++) {
            printf("%d", a_parrIntValue[k]); // Print the value of the current element
            if (k!= a_iNum - 1) { // Check if we are not at the last element
                printf(" "); // Print a space if not
            }
        }
        printf("\n"); // Print a newline after each pass
    }
}

