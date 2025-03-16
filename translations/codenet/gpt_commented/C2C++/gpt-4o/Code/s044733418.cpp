#include <iostream>
#include <algorithm> // For std::sort
#include <vector>

using namespace std;

// Function to compare two integers for sorting
bool compare(int a, int b)
{
    // Return true if a is less than b for descending order
    return a > b;
}

int main()
{
    // Declare a vector of integers
    vector<int> array(10);

    // Read 10 integers from standard input into the vector
    for(int i = 0; i < 10; i++)
        cin >> array[i];

    // Sort the array in descending order using std::sort and the compare function
    sort(array.begin(), array.end(), compare);

    // Print the first 3 elements of the sorted array
    for(int i = 0; i < 3; i++)
        cout << array[i] << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
