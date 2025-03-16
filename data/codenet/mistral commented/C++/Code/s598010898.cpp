
#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++) // A macro for iterating through arrays or vectors

int main(void) {
	int n; // Declare an integer variable 'n' to store the number of elements in arrays 'a' and 'b'
	cin >> n; // Read the number of elements 'n' from the standard input

	int a[100]; // Declare an integer array 'a' of size 100
	int b[100]; // Declare an integer array 'b' of size 100
	int sum = 0; // Declare an integer variable 'sum' and initialize it to zero

	rep(i, n) { // Iterate through the array 'a' and read its elements from the standard input
		cin >> a[i];
	}

	rep(i, n) { // Iterate through the array 'b' and read its elements from the standard input
		cin >> b[i];

		if (a[i] - b[i] > 0) { // Check if the difference between 'a[i]' and 'b[i]' is positive
			sum += a[i] - b[i]; // If it is, add the difference to the variable 'sum'
		}
	}

	cout << sum << endl; // Output the value of the variable 'sum' to the standard output
}