#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = 1e18;
const int INF_BIT60 = 1 << 60;

int memo[ALPHABET_NUM];
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		getline(cin, str);
		if (str.empty()) {
			break;
		}

		for (int i = 0; i < str.size(); i++) {
			char c = str[i];

			if ('a' <= c && c <= 'z') {
				// toUpper
				// c-('a'-'A')
				memo[c-'a']++;
			} else if ('A' <= c && c <= 'Z') {
				// toLower
				// c+('a'-'A')
				memo[c-'A']++;
			} else {
				// stay
				// c
				continue;
			}
		}
	}

	for (int i = 0; i < ALPHABET_NUM; i++) {
		cout << (char)(i + 'a') << " : " << memo[i] << endl;
	}
}

// MODはとったか？
// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

