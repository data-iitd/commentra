
#include<iostream>  // Include the standard input/output library
#include<algorithm>  // Include the algorithm library

// Define a function to compare two integers
bool compare(int a, int b)
{
    return (b < a);  // Return true if b is less than a, otherwise return false
}

int main(void)  // Define the main function
{
    int array[10], i;  // Declare an array of 10 integers and a loop variable
    for(i = 0; i!= 10; i++)  // Read 10 integers from the input
        std::cin >> array[i];
    std::sort(array, array+10, compare);  // Sort the array using the std::sort function and the compare function
    for(i = 0; i!= 3; i++)  // Print the first three elements of the sorted array
        std::cout << array[i] << std::endl;
    return 0;  // Return 0 to indicate successful execution
}
