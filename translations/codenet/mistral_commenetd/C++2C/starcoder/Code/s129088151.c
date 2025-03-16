
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<map.h>

// Declare variables
int n;
char str[10], com[13];
map<string, bool> T; // A map to store strings as keys and boolean values

int main() {
	// Read the number of input pairs from the standard input
	scanf("%d", &n);

	// Iterate through each input pair
	for (int i = 0; i < n; i++) {
		// Read the command and the string from the standard input
		scanf("%s%s", com, str);

		// If the command is 'i', add the string to the map with a value of true
		if (com[0] == 'i') {
			T[str] = true; // Set the value of the string as a key in the map to true
		}
		// If the command is not 'i', check if the string is present in the map and print the result accordingly
		else {
			if (T.find(str)!= T.end()) { // Check if the string is present in the map
				printf("yes\n"); // If present, print 'yes'
			}
			else {
				printf("no\n"); // If not present, print 'no'
			}
		}
	}
	// Return 0 to indicate successful execution of the program
	return 0;
}

