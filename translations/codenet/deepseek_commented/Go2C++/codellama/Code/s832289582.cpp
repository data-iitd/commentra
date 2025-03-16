
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime
int checkSubNumbers(int N, int P, string S) {
	int answer = 0;
	switch (P) {
	case 2:
	case 5:
		for (int i = N - 1; i >= 0; i--) {
			if (S[i] - '0' % P == 0) {
				answer += i + 1;
			}
		}
		break;
	default:
		int multiplier = 1;
		int prevRemaider = -1;
		vector<int> remainderLookup(P);
		for (int i = N - 1; i >= 0; i--) {
			int digit = S[i] - '0';
			int remainder;
			if (prevRemaider == -1) {
				remainder = digit % P;
			} else {
				remainder = (((multiplier * digit) % P) + prevRemaider) % P;
			}
			if (remainder == 0) {
				answer++;
			}
			answer += remainderLookup[remainder];
			remainderLookup[remainder]++;
			prevRemaider = remainder;
			multiplier = (multiplier * 10) % P;
		}
		break;
	}
	return answer;
}

int main() {
	int N, P;
	string S;
	cin >> N >> P >> S;
	cout << checkSubNumbers(N, P, S) << endl;
	return 0;
}

