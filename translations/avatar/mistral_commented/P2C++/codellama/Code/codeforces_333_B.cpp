#include <iostream>
using namespace std;

int main()
{
    // Take input as two integers n and m from the user
    int n, m;
    cin >> n >> m;

    // Initialize a list 'b' of length 2 * n with all elements as 1
    int b[2 * n];
    for (int i = 0; i < 2 * n; i++)
        b[i] = 1;

    // Set the first, last and middle elements of the list 'b' to 0
    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;

    // Iterate through the given 'm' pairs of row and column indices
    for (int i = 0; i < m; i++)
    {
        // Take row and column indices as input
        int r, c;
        cin >> r >> c;

        // Set the elements at the given row and column indices to 0 in the list 'b'
        b[r - 1] = b[n + c - 1] = 0;
    }

    // Check if n is odd and if the middle two elements of the list 'b' are 1, then set the middle element to 0
    if (n % 2 && b[n / 2] && b[n + n / 2])
        b[n / 2] = 0;

    // Calculate and print the sum of all elements in the list 'b'
    int sum = 0;
    for (int i = 0; i < 2 * n; i++)
        sum += b[i];
    cout << sum << endl;

    return 0;
}

