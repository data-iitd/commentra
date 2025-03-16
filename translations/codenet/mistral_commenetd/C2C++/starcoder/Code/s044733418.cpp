
#include<iostream>
// Include the standard input/output library

using namespace std;

int compare(int *a, int *b)
// Function to compare two integers for qsort
{
    return (*b - *a);
// Subtract the address of b from the address of a to get the difference between the two integers
}

int main(void)
{
    int array[10]; // Declare an array of 10 integers
// Initialize an array of 10 integers

    for(int i = 0; i < 10; i++) // Iterate through the array to read 10 integers
    {
        cin >> array[i];
// Read an integer from the user and store it in the array
    }

    sort(array, array+10);
// Sort the array using the quicksort algorithm and the compare function

    for(int i = 0; i < 3; i++) // Iterate through the first three elements of the sorted array
    {
        cout << array[i] << endl;
// Print the first three sorted integers
    }

    return 0;
// Return 0 to indicate successful execution of the program
}

