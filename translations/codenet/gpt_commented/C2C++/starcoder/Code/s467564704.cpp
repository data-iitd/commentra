#include<iostream>

using namespace std;

int main()
{
    // Declare a 4x4 array to hold input values and a variable for test cases
    int input[4][4], tc;

    // Read 3x3 input values from the user
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> input[i][j]; // Store each input value in the array
        }
    }

    // Read the number of test cases
    cin >> tc;
    int testcase;

    // Process each test case
    for(int i = 0; i < tc; i++)
    {
        cin >> testcase; // Read the current test case value

        // Check the input array for the testcase value and set it to 0 if found
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(input[i][j] == testcase)
                {
                    input[i][j] = 0; // Replace the found value with 0
                }
            }
        }
    }

    // Check for winning conditions in the modified input array
    if(input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0) // Check diagonal from top-left to bottom-right
    {
        cout << "Yes" << endl;
    }
    else if(input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0) // Check diagonal from top-right to bottom-left
    {
        cout << "Yes" << endl;
    }
    else if(input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0) // Check first row
    {
        cout << "Yes" << endl;
    }
    else if(input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0) // Check second row
    {
        cout << "Yes" << endl;
    }
    else if(input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0) // Check third row
    {
        cout << "Yes" << endl;
    }
    else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0) // Check first column
    {
        cout << "Yes" << endl;
    }
    else if(input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0) // Check second column
    {
        cout << "Yes" << endl;
    }
    else if(input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0) // Check third column
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl; // If no winning condition is met, output "No"
    }

    return 0; // End of the program
}

