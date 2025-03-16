#include <bits/stdc++.h>

using namespace std;

// Initialize a new scanner object
class Scanner {
public:
	Scanner() : r(cin.rdbuf()), p(0) {}
	void pre() {
		if (p >= len(buf)) {
			readLine();
			p = 0;
		}
	}
	void readLine() {
		buf.clear();
		for (char c = r.get(); c!= '\n'; c = r.get()) {
			buf.push_back(c);
		}
	}
	string Next() {
		pre();
		start = p;
		while (p < len(buf) && buf[p]!='') {
			p++;
		}
		string result(buf.begin() + start, buf.begin() + p);
		p++;
		return result;
	}
	int NextInt() {
		return atoi(Next().c_str());
	}
	vector<int> NextIntArray() {
		pre();
		start = p;
		vector<int> result;
		while (p < len(buf) && buf[p]!='') {
			p++;
		}
		string s(buf.begin() + start, buf.begin() + p);
		p++;
		istringstream iss(s);
		for (int v; iss >> v;) {
			result.push_back(v);
		}
		return result;
	}
	map<int, bool> NextMap() {
		pre();
		start = p;
		map<int, bool> result;
		while (p < len(buf) && buf[p]!='') {
			p++;
		}
		string s(buf.begin() + start, buf.begin() + p);
		p++;
		istringstream iss(s);
		for (int v; iss >> v;) {
			result[v] = true;
		}
		return result;
	}
private:
	istream& r;
	int p;
	vector<char> buf;
	int start;
};

// Initialize a new scanner object
Scanner sc;

// Read the number of elements in the array from the standard input
int n = sc.NextInt();

// Allocate memory for the array of size n
vector<float> arr(n);

// Read n integers from the standard input and store them in the array
for (int i = 0; i < n; i++) {
	arr[i] = float(sc.NextInt());
}

// Sort the array in ascending order
sort(arr.begin(), arr.end());

// Initialize a variable prev to store the previous element in the sorted array
float prev = arr[0];

// Iterate through the sorted array from the second element to the last
for (int i = 1; i < n; i++) {
	// Calculate the average of the previous and current elements
	prev = (prev + arr[i]) / 2;
}

// Print the result to the standard output
cout << prev << endl;

// 