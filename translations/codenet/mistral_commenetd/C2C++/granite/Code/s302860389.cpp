

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputNumbers;
    int a, b, c, d;
    int sum;
    char symbols[3];

    // Read input numbers from user
    cout << "Enter four integers separated by spaces: ";
    getline(cin, inputNumbers);

    // Extract each number from input string and convert to integer
    string temp;
    int index = 0;

    for (int i = 0; i < inputNumbers.length(); i++)
    {
	if (inputNumbers[i] =='')
	{
	    temp[1] = '\0';
	    a = stoi(temp);
	    temp[0] = inputNumbers[i + 1];
	    b = stoi(temp);
	    temp[0] = inputNumbers[i + 2];
	    c = stoi(temp);
	    temp[0] = inputNumbers[i + 3];
	    d = stoi(temp);
	    break;
	}
	else
	{
	    temp[index] = inputNumbers[i];
	    index++;
	}
    }

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
		    symbols[0] = '+';
		}
		else
		{
		    sum = a - b;
		    symbols[0] = '-';
		}

		if (j == 0)
		{
		    sum = sum + c;
		    symbols[1] = '+';
		}
		else
		{
		    sum = sum - c;
		    symbols[1] = '-';
		}

		if (k == 0)
		{
		    sum = sum + d;
		    symbols[2] = '+';
		}
		else
		{
		    sum = sum - d;
		    symbols[2] = '-';
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

