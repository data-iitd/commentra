#include<cstdio> // Include the standard C library for input/output operations
#include<map>    // Include the map library for efficient key-value pair storage
#include<string> // Include the string library for string manipulation
#include<iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'

int main() {
	int n; // Declare an integer variable to store the number of operations
	char str[10], com[13]; // Declare character arrays to store commands and strings
	map<string, bool> T; // Declare a map to store the presence of strings

	cin >> n; // Read the number of operations from the user
	for (int i = 0; i < n; i++) { // Loop through each operation
		scanf("%s%s", com, str); // Read the command and the string
		if (com[0] == 'i') T[string(str)] = true; // If the command is 'i', insert the string into the map
		else { // If the command is not 'i'
			if (T[string(str)]) printf("yes\n"); // Check if the string is present in the map and print 'yes'
			else printf("no\n"); // If the string is not present, print 'no'
		}
	}
	return 0; // Return 0 to indicate successful execution
}
