
#include <stdio.h> // Include standard input/output library
#include <string.h> // Include string manipulation library

int main(void) { // Declare the main function with no arguments and no return value
	char str[201], tmp[101]; // Declare two character arrays, str and tmp, with sizes 201 and 101 respectively
	char p[101]; // Declare another character array p with size 101
	int slen, plen; // Declare two integer variables, slen and plen, to store the length of str and p respectively
	int i, j, flag; // Declare three integer variables, i, j, and flag

	scanf("%s %s", str, p); // Read two strings from the standard input and store them in str and p respectively

	strcpy(tmp, str); // Copy the contents of str to tmp
	strcat(str, tmp); // Concatenate the contents of str and tmp, i.e., str now contains str concatenated with itself

	slen = strlen(str); // Get the length of str and store it in slen
	plen = strlen(p); // Get the length of p and store it in plen

	flag = 0; // Initialize flag to 0
	for (i = 0; i < slen - plen; i++) { // Iterate through the string str from the beginning to the end - plen characters
		if (strncmp(&str[i], p, plen) == 0) { // Compare the substring of str starting from index i with length plen to p
			flag = 1; // If the comparison is successful, set flag to 1
		}
	}

	if (flag) puts("Yes"); // If flag is 1, print "Yes" to the standard output
	else puts("No"); // If flag is 0, print "No" to the standard output

	return 0; // Indicate successful termination of the main function
}