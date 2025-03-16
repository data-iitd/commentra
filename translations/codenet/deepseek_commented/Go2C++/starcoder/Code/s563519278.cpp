#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int N; // Step 1: Reading the number of elements (N)
	cin >> N;
	vector<int> v(N); // Step 2: Initializing the array
	int a;
	for (int i = 1; i < N; i++) { // Step 3: Reading and counting elements
		cin >> a;
		v[a-1]++;
	}

	for (int e : v) { // Step 4: Writing the results
		cout << e << endl;
	}
}

