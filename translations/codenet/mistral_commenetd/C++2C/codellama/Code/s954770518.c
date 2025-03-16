#include<stdio.h>   // Include the standard I/O library for printf and scanf functions
#include<stdlib.h>  // Include the standard library for the sort function
#include<string.h>  // Include the string library for the strlen function

int main() // The main function is the entry point of the program
{
    int s[11]; // Declare an integer array 's' of size 11
    int i;     // Declare an integer variable 'i' for loop counter

    // Read 10 integers from the user and store them in the array 's'
    for(i=0;i<10;i++){
        scanf("%d",&s[i]); // Read an integer from the standard input and store it in the array 's' at the current index
    }

    // Sort the array 's' in ascending order using the sort function from the standard library
    qsort(s,10,sizeof(int),compare);

    // Print the 4th, 5th and 6th smallest elements from the sorted array 's'
    for(i=9;i>6;i--){ // Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
        printf("%d\n",s[i]); // Print the current element of the array 's' to the standard output
    }

    return 0; // Indicate that the program has executed successfully and terminate
}

int compare(const void *a, const void *b) // The compare function is used to compare the elements of the array 's'
{
    return *(int*)a - *(int*)b; // Return the difference between the two elements
}

