#include<bits/stdc++.h>
using namespace std;
int main()
{
	int input[4][4], tc;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			cin>>input[i][j];
			// Read the elements of the input array
		}
	}
	cin>>tc;
	// Read the number of test cases `tc` from the standard input.
	int testcase;
	for(int i = 0;i<tc;i++)
	{
		cin>>testcase;
		for(int m = 0;m<3;m++)
		{
			for(int n = 0;n<3;n++)
			{
				if(input[m][n] == testcase)
				{
					input[m][n] = 0;
					// If the given testcase is present in the input array, set its value to 0.
				}
			}
		}
	}
	// Check if all the elements of any of the three 1x1 sub-arrays are 0 or not.
	if(input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else if(input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0)
	{
		cout<<"Yes";
		// If yes, print "Yes" and exit the program.
		exit(0);
	}
	else
	{
		cout<<"No";	
		// If none of the above conditions are satisfied, print "No" and exit the program.
		exit(1);
	}
	return 0;
}
