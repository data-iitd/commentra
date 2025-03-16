
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Initialize a new vector to store input from standard input
	vector<int> ns;

	// Read the first line of input containing 4 integers and store them in ns vector
	cout << "Reading input" << endl;
	string line;
	getline(cin, line);
	stringstream ss(line);
	int n;
	while (ss >> n) {
		ns.push_back(n);
	}

	// Sort the ns vector in ascending order
	cout << "Sorting the numbers in ns vector" << endl;
	sort(ns.begin(), ns.end());

	// Check if the sorted ns vector matches the specific condition (1, 4, 7, 9)
	cout << "Checking the condition" << endl;
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		cout << "The condition is true, print YES" << endl;
		cout << "Output: YES" << endl;
		cout << endl;
		cout << "End of the program" << endl;
		return 0;
	} else {
		cout << "The condition is false, print NO" << endl;
		cout << "Output: NO" << endl;
		cout << endl;
		cout << "End of the program" << endl;
		return 0;
	}
}

