#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to read input from stdin
void readInput(vector<string> &input) {
	string s;
	while (getline(cin, s)) {
		input.push_back(s);
	}
}

// Function to write output to stdout
void writeOutput(vector<string> &output) {
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}

// Function to solve the problem
void solve(vector<string> &input, vector<string> &output) {
	// TODO: Write your code here
}

// Main function
int main() {
	// Reading input from stdin
	vector<string> input;
	readInput(input);

	// Preparing output buffer
	vector<string> output;

	// Solving the problem
	solve(input, output);

	// Writing output to stdout
	writeOutput(output);

	return 0;
}
