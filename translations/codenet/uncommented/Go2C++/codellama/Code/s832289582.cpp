
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checkSubNumbers(int N, int P, string S) {
	int answer = 0;
	switch (P) {
	case 2:
	case 5:
		for (int i = N - 1; i >= 0; i--) {
			int n = S[i] - '0';
			if (n % P == 0) {
				answer += i + 1;
			}
		}
		break;
	default:
		vector<int> remainderLookup(P);
		int multiplier = 1; // 10^i % P
		int prevRemaider = -1;
		int digit, remainder, count;
		for (int i = N - 1; i >= 0; i--) {
			digit = S[i] - '0';
			if (prevRemaider == -1) { // first digit
				remainder = digit % P;
			} else {
				remainder = (((multiplier * digit) % P) + prevRemaider) % P;
			}
			if (remainder == 0) {
				answer++;
			}
			count = remainderLookup[remainder];
			answer += count;
			count++;
			remainderLookup[remainder] = count;
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
	int answer = checkSubNumbers(N, P, S);
	cout << answer << endl;
	return 0;
}

