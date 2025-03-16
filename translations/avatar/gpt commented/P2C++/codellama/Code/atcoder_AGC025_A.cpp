#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Read input from the user
    string n;
    cin >> n;

    // Define a list of string representations of powers of ten
    vector<string> a = {"10", "100", "1000", "10000", "100000"};

    // Convert the input string into a list of integers and calculate the sum
    int new = 0;
    for (int i = 0; i < n.length(); i++)
    {
        new += n[i] - '0';
    }

    // Check if the input is one of the predefined values in the list 'a'
    if (find(a.begin(), a.end(), n) != a.end())
    {
        // If the input matches one of the predefined values, print 10
        cout << 10 << endl;
    }
    else
    {
        // If the input does not match, print the calculated sum
        cout << new << endl;
    }

    return 0;
}

