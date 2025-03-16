
#include<iostream>
#include<string>
#include<vector>
using namespace std;

# Declare and initialize variables
int main() {
	string s; # Declare a string variable 's' to store the input string
	cin >> s; # Read a string from the standard input and store it in 's'
	int n = s.size(); # Get the size of the string 's' and store it in 'n'
	int v[26]={0}; # Declare and initialize an integer array 'v' of size 26 with zeroes

	# Read each character of the string 's' and increment the corresponding index in array 'v'
	for (int i = 0;i < n;i++) {
		v[s[i] - 'a']++; # Increment the index 's[i] - 'a' in array 'v'
	}

	# Initialize answer string to "Yes"
	string ans = "Yes";

	# Check if all elements in array 'v' are even
	for (int i = 0;i < 26;i++) {
		if (v[i] % 2 != 0) { # Check if the current index in array 'v' is odd
			ans = "No"; # If so, set the answer string to "No"
			break; # Exit the loop as soon as an odd number is found
		}
	}

	# Print the answer
	cout << ans << endl;
}

