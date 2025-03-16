

#include <iostream> // Include standard input/output library
#include <string> // Include string manipulation library

int main(void) { // Declare the main function with no arguments and no return value
	std::string str, tmp, p; // Declare three string variables, str, tmp, and p
	int slen, plen; // Declare two integer variables, slen and plen, to store the length of str and p respectively
	int i, j, flag; // Declare three integer variables, i, j, and flag

	std::cin >> str >> p; // Read two strings from the standard input and store them in str and p respectively

	tmp = str; // Copy the contents of str to tmp
	str += tmp; // Concatenate the contents of str and tmp, i.e., str now contains str concatenated with itself

	slen = str.length(); // Get the length of str and store it in slen
	plen = p.length(); // Get the length of p and store it in plen

	flag = 0; // Initialize flag to 0
	for (i = 0; i < slen - plen; i++) { // Iterate through the string str from the beginning to the end - plen characters
		if (str.substr(i, plen) == p) { // Compare the substring of str starting from index i with length plen to p
			flag = 1; // If the comparison is successful, set flag to 1
		}
	}

	if (flag) std::cout << "Yes" << std::endl; // If flag is 1, print "Yes" to the standard output
	else std::cout << "No" << std::endl; // If flag is 0, print "No" to the standard output

	return 0; // Indicate successful termination of the main function
}

