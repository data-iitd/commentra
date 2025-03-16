#include<stdio.h>  // Include the standard input/output library

// Define a function to compare two integers
int compare(int *a, int *b)
{
    return (*b - *a);  // Return the difference between the two integers
}

int main(void)  // Define the main function
{
    int array[10], i;  // Declare an array of 10 integers and a loop variable
    for(i = 0; i != 10; i++)  // Read 10 integers from the input
        scanf("%d", array+i);
    qsort(array, 10, sizeof(int), compare);  // Sort the array using the qsort function and the compare function
    for(i = 0; i != 3; i++)  // Print the first three elements of the sorted array
        printf("%d\n", array[i]);
    return 0;  // Return 0 to indicate successful execution
}
