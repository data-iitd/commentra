
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Declare variables
int n;
char str[10], com[13];

// Define a struct to store strings as keys and boolean values
struct map {
	char *key;
	bool value;
};

// Define a function to add a string to the map
void add(struct map *T, char *str) {
	T->key = str;
	T->value = true;
}

// Define a function to check if a string is present in the map
bool check(struct map *T, char *str) {
	if (strcmp(T->key, str) == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	// Read the number of input pairs from the standard input
	scanf("%d", &n);

	// Iterate through each input pair
	for (int i = 0; i < n; i++) {
		// Read the command and the string from the standard input
		scanf("%s%s", com, str);

		// If the command is 'i', add the string to the map with a value of true
		if (com[0] == 'i') {
			add(T, str); // Set the value of the string as a key in the map to true
		}
		// If the command is not 'i', check if the string is present in the map and print the result accordingly
		else {
			if (check(T, str)) { // Check if the string is present in the map
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

