#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s; // Step 1: The program starts by taking a string input from the user.
	cin >> s;

	int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
	vector<int> counter;

	if (s == "") { // Step 3: It checks if the input string is empty and returns immediately if it is.
		return 0;
	}
	counter.push_back(0); // Step 4: It splits the input string into individual characters.
	for (int i = 0; i < s.length(); i++) {
		counter.push_back(0);
	}

	for (int i = 0; i < s.length(); i++) { // Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			count++;
		} else {
			counter[i] = count;
			count = 0;
		}
	}

	counter[s.length()] = count; // Step 6: It appends the final count to the counter array and sorts the array.
	sort(counter.begin(), counter.end());
	cout << counter[counter.size() - 1] << endl; // Step 7: Finally, it prints the maximum value in the sorted counter array.
	return 0;
}

