#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Take an integer 'n' as input from the user
    int n;
    cin >> n;

    // Take a list 'm' as input from the user, where each element is a single character
    string m;
    cin >> m;

    // Initialize a boolean variable 'possible' with a default value of True
    bool possible = true;

    // Iterate through each unique character 'i' in the list 'm'
    for (int i = 0; i < m.length(); i++)
    {
        // Check if the character 'i' appears more than 'n/2 + 1' times in the list 'm'
        if (count(m.begin(), m.end(), m[i]) >= n / 2 + 1)
        {
            // If the condition is true, set 'possible' to False and break the loop
            possible = false;
            break;
        }
    }

    // Print 'YES' if 'possible' is still True, otherwise print 'NO'
    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}

