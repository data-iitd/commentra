#include <iostream>
#include <vector>

using namespace std;

// This is the main function where the program starts execution
int main()
{
    // Declare a vector 'a' to store integers and an integer variable 'n'
    vector<int> a(1000);
    int n, d = 0; // Initialize a variable 'd' to keep track of the number of swaps made during sorting

    // Read the size of the array from the user
    cin >> n;

    // Read 'n' integers from the user and store them in the vector 'a'
    for(int i = 0; i < n; i++)
    {
        cin >> a[i]; // Read an integer and store it in the current index of the vector 'a'
    }

    // Implement bubble sort algorithm to sort the vector 'a' in ascending order
    for (int i = 0; i < n; i++) // Iterate through each index of the vector 'a'
    {
        for (int j = n - 1; j >= i + 1; j--) // Iterate through the vector from the last index to the current index
        {
            if (a[j] < a[j - 1]) // Check if the current element is smaller than the previous element
            {
                swap(a[j], a[j - 1]); // Swap the elements if they are in the wrong order
                d++; // Increment the swap counter
            }
        }
    }

    // Print the sorted vector 'a'
    cout << a[0]; // Print the first element of the vector
    for(int i = 1; i < n; i++) // Iterate through the remaining elements of the vector
    {
        cout << " " << a[i]; // Print each element preceded by a space
    }
    cout << endl; // Print a newline character at the end of the line

    // Print the number of swaps made during sorting
    cout << d << endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
