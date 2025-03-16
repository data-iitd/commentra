#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // Define the number of elements 'n' and the difference 'd' in the input list
    int n, d;
    cin >> n >> d;

    // Initialize an empty list 'x' to store the input elements
    vector<int> x;

    // Initialize variables 'm' and 'q' to 0
    int m = 0, q = 0;

    // Read the 'n' elements from the input and convert them to integers
    string s;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> s)
    {
        x.push_back(stoi(s));
    }

    // Iterate through the list 'x' to find the elements that are not in increasing order
    for (int i = 0; i < x.size() - 1; i++)
    {
        // Check if the current element is greater than or equal to the next element
        if (x[i] >= x[i+1])
        {
            // Calculate the number of elements that need to be added to the next element
            q = (x[i] - x[i+1]) / d + 1;
            // Add the calculated number of elements to the current and next elements
            m += q;
            x[i+1] += q * d;
        }
    }

    // Print the final result 'm'
    cout << m << endl;

    return 0;
}

