#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // Read a line of input
    string line;
    getline(cin, line);

    // Split the line into components
    istringstream iss(line);
    vector<int> a;
    int i;
    while (iss >> i)
    {
        a.push_back(i);
    }

    // Iterate over the list 'a' using enumerate to get both the index (e) and the value (i)
    for (int e = 0; e < a.size(); e++)
    {
        // Check if the current value is zero
        if (a[e] == 0)
        {
            // Print the index (1-based) of the first occurrence of zero
            cout << e + 1 << endl;
            // Exit the loop after finding the first zero
            break;
        }
    }

    return 0;
}

