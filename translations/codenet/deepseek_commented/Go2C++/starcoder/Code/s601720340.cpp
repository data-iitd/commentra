
#include <bits/stdc++.h>

using namespace std;

// Constants
const int magic = 1000000007;

// Variables
int N;
int p[200000];

// Functions
int find(int n);
void solve();

// Main
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// PARSE HELPER SESSION

	// X := io.NextInt()
	// N = io.NextInt()
	// for i := 0; i < N; i++ {
	// 	p[i] = io.NextInt()
	// }

	// Main logic to find the closest number to X in the array p.
	X := io.NextInt();
	N = io.NextInt();
	for (int i = 0; i < N; i++) {
		p[i] = io.NextInt();
	}

	// Search for the closest number to X in the array p.
	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) {
			cout << X - i << endl;
			return 0;
		}
		if (find(X + i) == 1) {
			cout << X + i << endl;
			return 0;
		}
	}
}

// Functions

int find(int n) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0;
		}
	}
	return 1;
}

// END-OF-CODE

