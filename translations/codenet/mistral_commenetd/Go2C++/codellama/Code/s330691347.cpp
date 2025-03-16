
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function out is used to print the output to the console
void out(string x) {
	//	cout << x << endl;
}

// Function nextInt reads an integer from the input
int nextInt() {
	int x;
	cin >> x;
	return x;
}

// Function nextString reads a string from the input
string nextString() {
	string x;
	cin >> x;
	return x;
}

// Define a struct Data to represent a single data point
struct Data {
	string X;
};

// Define a vector of Data named s
vector<Data> s;

// Function sortData sorts the vector s based on X field
void sortData(vector<Data> &s) {
	sort(s.begin(), s.end(), [](Data a, Data b) {
		return a.X < b.X;
	});
}

// Main function starts here
int main() {
	// Read number of data points N from the input
	int N = nextInt();

	// Read number of queries L from the input
	int L = nextInt();

	// Read data points X from the input and store them in the vector s
	for (int i = 0; i < N; i++) {
		Data d;
		d.X = nextString();
		s.push_back(d);
	}

	// Print the number of data points N, number of queries L, and the vector s
	out(to_string(N) + " " + to_string(L) + " " + to_string(s));

	// Sort the vector s in ascending order based on X field
	sortData(s);

	// Initialize an empty string ans to store the concatenated X values
	string ans = "";

	// Iterate through the vector s and concatenate X values to the string ans
	for (int i = 0; i < N; i++) {
		ans += s[i].X;
	}

	// Print the concatenated string ans to the console
	cout << ans << endl;

	return 0;
}

