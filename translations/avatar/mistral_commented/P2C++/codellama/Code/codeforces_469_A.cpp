#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    // User inputs the maximum level of the set
    int max_level;
    cin >> max_level;

    // User inputs two lists, x and y, separated by a newline
    string x_str, y_str;
    getline(cin, x_str);
    getline(cin, y_str);

    // Remove the first element from both lists, as they are not part of the sets
    x_str.erase(0, 1);
    y_str.erase(0, 1);

    // Convert both lists to sets for faster set operations
    set<int> x, y;
    for (int i = 0; i < x_str.size(); i++)
    {
        x.insert(x_str[i] - '0');
    }
    for (int i = 0; i < y_str.size(); i++)
    {
        y.insert(y_str[i] - '0');
    }

    // Check if zero is present in the first set
    if (x.find(0) != x.end())
    {
        // If it is, remove it
        x.erase(0);
    }
    // Else, check if zero is present in the second set
    else
    {
        if (y.find(0) != y.end())
        {
            // If it is, remove it
            y.erase(0);
        }
    }

    // Combine both sets into a new set z
    set<int> z = x.union(y);

    // Check if the size of the combined set is equal to the maximum level
    if (z.size() != max_level)
    {
        // If not, print an error message
        cout << "Oh, my keyboard!" << endl;
    }
    // Else, print a success message
    else
    {
        cout << "I become the guy." << endl;
    }

    return 0;
}

