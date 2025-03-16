
#include <iostream>
#include <vector>
using namespace std;

// Main function
int main() {
	// Read input n and k
	int n, k;
	cin >> n >> k;

	// Read input array a
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Initialize light array based on initial a array
	vector<int> light(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int r, l;
		r = i - a[i];
		l = i + a[i];
		light[(r < 0? 0 : r)]++;
		light[(l + 1 > n? n + 1 : l + 1)]--;
	}

	// Perform k iterations
	for (int i = 0; i < k; i++) {
		// Initialize temporary array tmpa
		vector<int> tmpa(n);
		int sum = 0;
		for (int j = 0; j < n; j++) {
			tmpa[j] = a[j];
			sum += light[j];
			a[j] = sum;
		}

		// Update light array based on new a array
		for (int j = 0; j < n; j++) {
			int r = j - a[j];
			int l = j + a[j];
			light[(r < 0? 0 : r)]--;
			light[(l + 1 > n? n + 1 : l + 1)]++;
			r = j - a[j];
			l = j + a[j];
			light[(r < 0? 0 : r)]++;
			light[(l + 1 > n? n + 1 : l + 1)]--;
		}

		// Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
		bool isSame = true;
		for (int j = 0; j < n - 1; j++) {
			if (a[j]!= a[j + 1]) {
				isSame = false;
				break;
			}
		}
		if (isSame && a[0] == n) {
			break;
		}
	}

	// Print out updated a array
	for (int j = 0; j < n; j++) {
		cout << a[j];
		cout << (j == n - 1? "\n" : " ");
	}

	return 0;
}

