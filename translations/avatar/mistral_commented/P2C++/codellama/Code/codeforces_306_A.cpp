#include <iostream>
using namespace std;

int main()
{
    int n, m, q, r, i;

    // Read the input from the user
    cin >> n >> m;

    // Calculate the quotient and remainder of n divided by m
    q = n / m;
    r = n % m;

    // Initialize the a list with q repeated m times
    int a[m];
    for (i = 0; i < m; i++)
        a[i] = q;

    // Increment the corresponding elements in the a list for the remaining elements
    for (i = 0; i < r; i++)
        a[i]++;

    // Print each element of the a list separated by a space
    for (i = 0; i < m; i++)
        cout << a[i] << " ";

    // End with comment "