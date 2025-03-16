
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // Read the number of elements in the list
    int n;
    cin >> n;

    // Read the list of integers and count the occurrences of each integer
    map<int, int> w;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        w[x]++;
    }

    // Initialize a variable to store the count of pairs
    int c = 0;

    // Iterate over each integer in the Counter object
    for (auto it = w.begin(); it != w.end(); it++)
    {
        // If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
        if (it->first == 0)
        {
            c += it->second * (it->second - 1);
        }
        // If the integer is not 0, check if its negative counterpart is also in the Counter
        else
        {
            if (w.find(-it->first) != w.end())
            {
                // Calculate the number of ways to choose 2 items from the occurrences of i and -i
                c += it->second * w[-it->first];
            }
        }
    }

    // Print the result of c // 2, which represents the number of unique pairs
    cout << c / 2 << endl;

    return 0;
}

