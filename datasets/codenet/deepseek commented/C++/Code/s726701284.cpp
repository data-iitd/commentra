#include<iostream> 
#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 
int main()
{
	// Step 1: Read a string from the user
	string s;
	cin >> s;
	
	// Step 2: Iterate through each letter from 'a' to 'z'
	for (char i = 'a'; i <= 'z'; i++)
	{
		// Step 3: Count how many times the current letter appears in the input string
		int a = 0;
		for (int j = 0; j < s.size();j++)
		{
			if (i==s.at(j))
			{
				a++;
			}
		}
		
		// Step 4: If the letter does not appear in the input string, print it and break out of the loop
		if (a==0)
		{
			cout << i << endl;
			break;
		} 
		
		// Step 5: If all letters from 'a' to 'z' appear in the input string, print "None"
		if (i=='z')
		{
			cout << "None" << endl;
			break;
		}
	}
}