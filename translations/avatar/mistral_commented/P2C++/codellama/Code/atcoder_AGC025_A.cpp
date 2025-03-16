#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Take an input from the user and assign it to the variable 'n'
    string n;
    cin >> n;

    // Initialize a vector 'a' with some strings representing numbers
    vector<string> a = { "10" , "100" , "1000" , "10000" , "100000" };

    // Convert each element of the input 'n' to an integer using the 'map' function
    // and then sum up all the integers using the 'sum' function and assign the result to the variable 'new'
    int new = accumulate(n.begin(), n.end(), 0, [](int x, char y) { return x + (y - '0'); });

    // Check if the input 'n' is present in the vector 'a'
    if (find(a.begin(), a.end(), n) != a.end())
    {
        // If the input 'n' is present in the vector 'a', then print the number 10
        cout << 10 << endl;
    }
    else
    {
        // If the input 'n' is not present in the vector 'a', then print the value of the variable 'new'
        cout << new << endl;
    }

    return 0;
}

