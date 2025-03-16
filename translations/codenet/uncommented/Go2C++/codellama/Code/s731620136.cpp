
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;

	if (N == 0) {
	}

	if (N < 4) {
		cout << 0 << endl;
		return 0;
	}

	int nr = 0, nb = 0, ng = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') {
			nr++;
		}

		if (S[i] == 'B') {
			nb++;
		}

		if (S[i] == 'G') {
			ng++;
		}
	}

	int same = 0;
	// int etot = 0;
	for (int a = 1; a < N; a++) {
		int i = 0;
		int j = 1 * a;
		int k = 2 * a;
		if (k >= N) {
			break;
		}
		while (k < N) {
			// etot++;
			// cout << "(" << etot << ") [" << a << "] (" << i << ", " << j << ", " << k << ")";
			if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
				same++;
				// cout << " (" << same << ")";
			}
			// cout << endl;
			i++;
			j++;
			k++;
		}
	}

	int tot = nr * nb * ng;

	// int sum = 0;
	// int sum2 = 0;
	// for (int k = 2; k < N; k++) {
	// 	for (int j = 1; j < k; j++) {
	// 		for (int i = 0; i < j; i++) {
	// 			if (j - i == k - j) {
	// 				if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
	// 					sum2++;
	// 				}
	// 				continue;
	// 			}

	// 			if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
	// 				sum++;
	// 			}
	// 		}
	// 	}
	// }

	// cout << tot << " " << same << " " << sum << " " << sum2 << endl;
	cout << tot - same << endl;

	return 0;
}

