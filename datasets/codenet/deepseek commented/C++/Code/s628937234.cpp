#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	using namespace std;
	
	// Declare two string variables, s and t
	string s, t;
	
	// Read a string from the standard input and store it in s
	cin >> s;
	
	// Assign the first character of s to t
	t = s[0];
	
	// Append the size of s minus 2 to t
	t += to_string(s.size() - 2);
	
	// Append the last character of s to t
	t += s[s.size() - 1];
	
	// Print the modified string t
	cout << t << endl;
}
