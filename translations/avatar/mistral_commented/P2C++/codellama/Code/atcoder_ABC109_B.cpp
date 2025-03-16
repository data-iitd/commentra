#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Read the number of elements in the list from user input
    int n;
    cin >> n;

    // Initialize an empty dictionary 's' with default value 0 using map
    map<string, int> s;

    // Create an empty list 'l' with length 'n' by reading elements from user input
    string l[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    // Initialize a flag 'f' with value 'Yes'
    string f = "Yes";

    // Iterate through each element 'v' in the list 'l'
    for (int i = 0; i < n; i++)
    {
        // Increment the count of 'v' in dictionary 's'
        s[l[i]] += 1;

        // Check if the count of 'v' in dictionary 's' is greater than or equal to 2
        if (s[l[i]] >= 2)
        {
            // If yes, set the flag 'f' to 'No'
            f = "No";
        }

        // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
        if (i != -1 && l[i - 1][l[i - 1].length() - 1] != l[i][0])
        {
            // If yes, set the flag 'f' to 'No'
            f = "No";
        }
    }

    // Print the final value of flag 'f'
    cout << f << endl;

    return 0;
}

