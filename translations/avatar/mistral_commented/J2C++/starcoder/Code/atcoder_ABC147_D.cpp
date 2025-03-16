
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long startTime = clock(); // Start time measurement
	int n;
	cin >> n;
	long long A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	long long div = (long long)pow(10, 9) + 7;
	long long ans = 0;
	for (int i = 0; i < 60; i++) {
		long long a = 0;
		long long count1 = 0;
		for (int j = 0; j < n; j++) {
			if ((A[j] >> i & 1) == 1) {
				count1++;
			}
		}
		a = a + count1 * (n - count1);
		for (int j = 0; j < i; j++) {
			a = (a << 1) % div;
		}
		ans += a;
		ans %= div;
	}
	cout << ans << endl;
	long long endTime = clock(); // End time measurement
	cout << "Time taken by the program is : " << (endTime - startTime) << " milliseconds" << endl; // Printing the time taken by the program to execute
	return 0;
}

