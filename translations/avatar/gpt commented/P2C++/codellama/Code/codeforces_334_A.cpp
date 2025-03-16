#include <iostream>
using namespace std;

int main()
{
    // Read an integer input from the user
    int n;
    cin >> n;

    // Initialize two variables: 'i' starting from 1 and 'j' starting from n*n
    int i = 1, j = n * n;

    // Loop until 'i' is less than 'j'
    while (i < j)
    {
        // Print the current values of 'i' and 'j'
        cout << i << " " << j << endl;

        // Increment 'i' to move towards the center
        i += 1;

        // Decrement 'j' to move towards the center
        j -= 1;
    }

    return 0;
}
