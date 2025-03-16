#include <iostream>
using namespace std;

int main()
{
    // Read the number of elements from user input
    int n;
    cin >> n;

    // Initialize an empty list to store the elements
    int l[n];

    // Loop to read 'n' integers from user input and append them to the list
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    // Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
    int ans = n - 1;

    // Initialize a variable to keep track of the last element processed
    int last = 0;

    // Loop through each element in the list
    for (int i = 0; i < n; i++)
    {
        // Calculate the distance from the last element to the current element
        // and add 1 for the step to the current element
        ans += abs(last - l[i]) + 1;

        // Update 'last' to the current element for the next iteration
        last = l[i];
    }

    // Print the final calculated answer
    cout << ans << endl;

    return 0;
}

