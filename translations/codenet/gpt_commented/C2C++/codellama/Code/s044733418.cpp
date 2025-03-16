#include<iostream>
#include<algorithm>

// Function to compare two integers for sorting
bool compare(int a, int b)
{
    // Return the difference between b and a for descending order
    return (b - a);
}

int main(void)
{
    // Declare an array of integers and a variable for iteration
    int array[10], i;

    // Read 10 integers from standard input into the array
    for(i = 0; i != 10; i++)
        std::cin >> array[i];

    // Sort the array in descending order using std::sort and the compare function
    std::sort(array, array + 10, compare);

    // Print the first 3 elements of the sorted array
    for(i = 0; i != 3; i++)
        std::cout << array[i] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

