#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Create a list 'A' from the input, which is a sequence of space-separated integers
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // Check if the second or third element of the list 'A' is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0])
    {
        // If the condition is true, print '0'
        cout << 0 << endl;
    }
    else
    {
        // If the condition is false, sort the list 'A' in ascending order
        sort(A, A + n);

        // Print the difference between the third and second elements of the sorted list
        cout << A[2] - A[1] << endl;
    }

    return 0;
}

