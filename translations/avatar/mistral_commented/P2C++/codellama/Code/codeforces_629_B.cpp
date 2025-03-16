#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    // Declaring the variables m and f with zero values for all indices up to N
    int N = 368;
    int m[N] = {0};
    int f[N] = {0};

    // Reading the number of operations from the standard input and processing each operation
    int num_operations;
    cin >> num_operations;
    for (int i = 0; i < num_operations; i++)
    {
        // Reading an operation line and splitting it into components
        string operation;
        cin >> operation;
        stringstream ss(operation);
        string x;
        int a, b;
        ss >> x >> a >> b;
        b = b + 1;
        // If the operation is 'M', updating the m array accordingly
        if (x == "M")
        {
            m[a] += 2;
            m[b] -= 2;
        }
        // If the operation is 'F', updating the f array accordingly
        else
        {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    // Initializing three variables a, b, and c with zeros
    int a = 0, b = 0, c = 0;

    // Calculating the prefix sums of m and f arrays
    for (int i = 0; i < N; i++)
    {
        // Updating the variables a and b with the sum of m and f arrays respectively
        a += m[i];
        b += f[i];
        // Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
        if (min(a, b) > c)
        {
            c = min(a, b);
        }
    }

    // Printing the result, which is the minimum of the prefix sums of m and f arrays
    cout << c << endl;

    return 0;
}

