
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Initialize an empty string variable 's' to store the input DNA sequence
	string s;

	// Read the input DNA sequence from the standard input using cin.get() function
	getline(cin, s);

	// Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
	// and a vector 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
	int count = 0;
	vector<int> counter;

	// Check if the input DNA sequence is empty or not
	if (s == "") {
		// If the input DNA sequence is empty, return without doing anything
		return 0;
	}

	// Initialize the first element of the 'counter' vector with an initial count of 0
	counter.push_back(0);

	// Split the input DNA sequence into a vector 'li' of individual nucleotides using stringstream.str() function
	stringstream ss(s);
	string token;
	vector<string> li;
	while (getline(ss, token, ' ')) {
		li.push_back(token);
	}

	// Iterate through each nucleotide in the 'li' vector using a for loop
	for (int i = 0; i < li.size(); i++) {
		// Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
		if (li[i] == "A" || li[i] == "C" || li[i] == "G" || li[i] == "T") {
			// If the current nucleotide is a valid nucleotide, increment the 'count' variable
			count++;
		} else {
			// If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' vector and reset the 'count' variable to 0
			counter.push_back(count);
			count = 0;
		}
	}

	// Append the final count of nucleotides in the last sub-sequence to the 'counter' vector
	counter.push_back(count);

	// Sort the 'counter' vector in ascending order using sort() function
	sort(counter.begin(), counter.end());

	// Print the last element of the sorted 'counter' vector, which represents the maximum count of nucleotides in any sub-sequence
	cout << counter[counter.size() - 1] << endl;

	return 0;
}

