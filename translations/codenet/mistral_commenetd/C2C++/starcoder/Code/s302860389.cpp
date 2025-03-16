
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Initialize variables
    string inputNumbers;
    string temp;
    int a, b, c, d;
    int sum;
    string symbols;

    // Read input numbers from user
    cout << "Enter four integers separated by spaces: ";
    cin >> inputNumbers;

    // Extract each number from input string and convert to integer
    temp = inputNumbers.substr(0, 1);
    a = atoi(temp.c_str());
    temp = inputNumbers.substr(1, 1);
    b = atoi(temp.c_str());
    temp = inputNumbers.substr(2, 1);
    c = atoi(temp.c_str());
    temp = inputNumbers.substr(3, 1);
    d = atoi(temp.c_str());

    // Perform arithmetic operations and check for the sum equal to 7
    for (int i = 0; i < 2; i++) // outer loop
    {
	for (int j = 0; j < 2; j++) // middle loop
	{
	    for (int k = 0; k < 2; k++) // inner loop
	    {
		// Assign symbols based on the position of current number
		if (i == 0)
		{
		    sum = a + b;
		    symbols = "+";
		}
		else
		{
		    sum = a - b;
		    symbols = "-";
		}

		if (j == 0)
		{
		    sum = sum + c;
		    symbols = symbols + "+";
		}
		else
		{
		    sum = sum - c;
		    symbols = symbols + "-";
		}

		if (k == 0)
		{
		    sum = sum + d;
		    symbols = symbols + "+";
		}
		else
		{
		    sum = sum - d;
		    symbols = symbols + "-";
		}

		// Check if the sum is equal to 7
		if (sum == 7)
		{
		    cout << a << symbols[0] << b << symbols[1] << c << symbols[2] << d << " = 7" << endl;

		    // If sum is equal to 7, exit the loop and return 0
		    return 0;
		}
	    }
	}
    }

    // If no combination of four numbers results in a sum of 7, return 0
    return 0;
}

