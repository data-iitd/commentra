#include<stdio.h>

// Function to compare two integers for sorting
int compare(int *a, int *b)
{
    // Return the difference between b and a for descending order
    return (*b - *a);
}

int main(void)
{
    // Declare an array of integers and a variable for iteration
    int array[10], i;

    // Read 10 integers from standard input into the array
    for(i = 0; i != 10; i++)
        scanf("%d", array + i);

    // Sort the array in descending order using qsort and the compare function
    qsort(array, 10, sizeof(int), compare);

    // Print the first 3 elements of the sorted array
    for(i = 0; i != 3; i++)
        printf("%d\n", array[i]);

    // Return 0 to indicate successful completion of the program
    return 0;
}
