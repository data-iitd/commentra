#include <bits/stdc++.h>

using namespace std;

// Define a type Data to represent a single data point
struct Data {
	string X;
};

// Define a type Datas as a vector of Data
typedef vector<Data> Datas;

// Function out is used to print the output to the console
void out(const Datas &s) {
	for (auto &e : s) {
		cout << e.X << " ";
	}
	cout << endl;
}

// Main function starts here
int main() {
	// Read number of data points N from the input
	int N; cin >> N;

	// Read number of queries L from the input
	int L; cin >> L;

	// Initialize a vector of Data type named s with capacity N
	Datas s(N);

	// Read data points X from the input and store them in the vector s
	for (int i = 0; i < N; i++) {
		cin >> s[i].X;
	}

	// Print the number of data points N, number of queries L, and the vector s
	out(s);

	// Sort the vector s in ascending order based on X field
	sort(s.begin(), s.end(), [](Data &a, Data &b) {
		return a.X < b.X;
	});

	// Initialize an empty string ans to store the concatenated X values
	string ans = "";

	// Iterate through the vector s and concatenate X values to the string ans
	for (int i = 0; i < N; i++) {
		ans += s[i].X;
	}

	// Print the concatenated string ans to the console
	cout << ans << endl;
}

