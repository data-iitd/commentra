
#include<iostream> 
#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 

// Declare a string variable 's' and read its value from the standard input using cin.
int main()
{
	string s;
	cin >> s;

	// Start a for loop that iterates through all the lowercase letters from 'a' to 'z'.
	for (char i = 'a'; i <= 'z'; i++)
	{
		int a = 0; // Initialize an integer variable 'a' to 0.

		// Start another for loop that iterates through all the characters in the string 's'.
		for (int j = 0; j < s.size();j++)
		{
			// Inside the inner for loop, we check if the current character 'i' matches the character at the current position 'j' in the string 's'. If it does, we increment the value of 'a'.
			if (i==s.at(j))
			{
				a++;
			}
		}

		// After the inner for loop, we check if the value of 'a' is 0. If it is, it means that the character 'i' does not appear in the string 's', so we print it to the standard output and break out of the outer for loop using the 'break' statement.
		if (a==0)
		{
			cout << i << endl;
			break;
		}

		// If the character 'i' is 'z', we print "None" to the standard output and break out of the outer for loop using the 'break' statement.
		if (i=='z')
		{
			cout << "None" << endl;
			break;
		}
	}
}