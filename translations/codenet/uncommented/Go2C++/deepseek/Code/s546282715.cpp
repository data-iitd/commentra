#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

string getNextWord(istream& is) {
	string word;
	is >> word;
	return word;
}

int getNextInt(istream& is) {
	int number;
	is >> number;
	return number;
}

int main(int argc, char* argv[]) {
	istream* fp = &cin;
	if (argc > 1) {
		fp = new ifstream(argv[1]);
	}

	unordered_set<int> aa;
	int n = getNextInt(*fp);
	int m = getNextInt(*fp);
	for (int i = 0; i < m; i++) {
		aa.insert(getNextInt(*fp));
	}

	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			if (aa.find(i + ii) != aa.end()) {
				continue;
			}
			dp[i + ii] += dp[i];
			dp[i + ii] %= 1000000007;
		}
	}
	cout << dp[n] << endl;

	if (argc > 1) {
		delete fp;
	}
	return 0;
}
