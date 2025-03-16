#include <bits/stdc++.h>

using namespace std;

// out is a utility function for printing output, currently commented out.
void out(const vector<string> &x) {
	//	for (auto &s : x) {
	//		cout << s << endl;
	//	}
}

// Data represents a single data entry with a string field.
struct Data {
	string X;
};

// Datas is a slice of Data, implementing sort.Interface.
struct Datas : public vector<Data> {
	bool operator()(const Data &a, const Data &b) {
		return a.X < b.X; // Sort based on the string field X
	}
};

int main() {
	int N, L;
	cin >> N >> L; // Read the number of data entries and an additional integer (not used further in the code)
	Datas s(N); // Create a slice of Datas with length N

	// Read N strings into the slice s
	for (int i = 0; i < N; i++) {
		cin >> s[i].X; // Populate each Data entry with a string
	}

	// out(N, L, s); // Output the initial values (commented out)
	sort(s.begin(), s.end()); // Sort the slice of Data entries
	// out(s); // Output the sorted slice (commented out)

	// Concatenate all strings in the sorted slice into a single result
	string ans = "";
	for (int i = 0; i < N; i++) {
		ans += s[i].X; // Append each string to ans
	}
	cout << ans << endl; // Print the concatenated result
}

