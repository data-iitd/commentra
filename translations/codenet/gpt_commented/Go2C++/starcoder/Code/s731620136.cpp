
#include <bits/stdc++.h>

using namespace std;

// Scanner class for handling input
class Scanner {
public:
	Scanner(istream& stream) : stream(stream) {}
	int nextInt() {
		int n;
		stream >> n;
		return n;
	}
	string nextStr() {
		string s;
		stream >> s;
		return s;
	}
	vector<int> nextIntSlice(int n) {
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = nextInt();
		}
		return res;
	}
	vector<float> nextFloatSlice(int n) {
		vector<float> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = nextFloat();
		}
		return res;
	}
	vector<string> nextStrSlice(int n) {
		vector<string> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = nextStr();
		}
		return res;
	}
	vector<char> nextCharSlice(int n) {
		vector<char> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = nextChar();
		}
		return res;
	}
	vector<bool> nextBoolSlice(int n) {
		vector<bool> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = nextBool();
		}
		return res;
	}
	void ignoreLine() {
		string s;
		getline(stream, s);
	}
	void ignoreWord() {
		string s;
		stream >> s;
	}
	void ignoreWords(int n) {
		for (int i = 0; i < n; i++) {
			ignoreWord();
		}
	}
	void ignoreLine(int n) {
		for (int i = 0; i < n; i++) {
			ignoreLine();
		}
	}
	void ignoreLines(int n) {
		for (int i = 0; i < n; i++) {
			ignoreLine();
		}
	}
	void ignoreUntil(string s) {
		string t;
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(char c) {
		string t;
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		for (int i = 0; i < q; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		for (int i = 0; i < q; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		for (int i = 0; i < q; i++) {
			stream >> t;
		}
		for (int i = 0; i < r; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		for (int i = 0; i < q; i++) {
			stream >> t;
		}
		for (int i = 0; i < r; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, string s) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		for (int i = 0; i < q; i++) {
			stream >> t;
		}
		for (int i = 0; i < r; i++) {
			stream >> t;
		}
		for (int i = 0; i < s; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, char c) {
		string t;
		for (int i = 0; i < n; i++) {
			stream >> t;
		}
		for (int i = 0; i < m; i++) {
			stream >> t;
		}
		for (int i = 0; i < o; i++) {
			stream >> t;
		}
		for (int i = 0; i < p; i++) {
			stream >> t;
		}
		for (int i = 0; i < q; i++) {
			stream >> t;
		}
		for (int i = 0; i < r; i++) {
			stream >> t;
		}
		for (int i = 0; i < s; i++) {
			stream >> t;
		}
		while (stream >> t) {
			if (t == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, int t, string s) {
		string u;
		for (int i = 0; i < n; i++) {
			stream >> u;
		}
		for (int i = 0; i < m; i++) {
			stream >> u;
		}
		for (int i = 0; i < o; i++) {
			stream >> u;
		}
		for (int i = 0; i < p; i++) {
			stream >> u;
		}
		for (int i = 0; i < q; i++) {
			stream >> u;
		}
		for (int i = 0; i < r; i++) {
			stream >> u;
		}
		for (int i = 0; i < s; i++) {
			stream >> u;
		}
		for (int i = 0; i < t; i++) {
			stream >> u;
		}
		while (stream >> u) {
			if (u == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, int t, char c) {
		string u;
		for (int i = 0; i < n; i++) {
			stream >> u;
		}
		for (int i = 0; i < m; i++) {
			stream >> u;
		}
		for (int i = 0; i < o; i++) {
			stream >> u;
		}
		for (int i = 0; i < p; i++) {
			stream >> u;
		}
		for (int i = 0; i < q; i++) {
			stream >> u;
		}
		for (int i = 0; i < r; i++) {
			stream >> u;
		}
		for (int i = 0; i < s; i++) {
			stream >> u;
		}
		for (int i = 0; i < t; i++) {
			stream >> u;
		}
		while (stream >> u) {
			if (u == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, int t, int u, string s) {
		string v;
		for (int i = 0; i < n; i++) {
			stream >> v;
		}
		for (int i = 0; i < m; i++) {
			stream >> v;
		}
		for (int i = 0; i < o; i++) {
			stream >> v;
		}
		for (int i = 0; i < p; i++) {
			stream >> v;
		}
		for (int i = 0; i < q; i++) {
			stream >> v;
		}
		for (int i = 0; i < r; i++) {
			stream >> v;
		}
		for (int i = 0; i < s; i++) {
			stream >> v;
		}
		for (int i = 0; i < t; i++) {
			stream >> v;
		}
		for (int i = 0; i < u; i++) {
			stream >> v;
		}
		while (stream >> v) {
			if (v == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, int t, int u, char c) {
		string v;
		for (int i = 0; i < n; i++) {
			stream >> v;
		}
		for (int i = 0; i < m; i++) {
			stream >> v;
		}
		for (int i = 0; i < o; i++) {
			stream >> v;
		}
		for (int i = 0; i < p; i++) {
			stream >> v;
		}
		for (int i = 0; i < q; i++) {
			stream >> v;
		}
		for (int i = 0; i < r; i++) {
			stream >> v;
		}
		for (int i = 0; i < s; i++) {
			stream >> v;
		}
		for (int i = 0; i < t; i++) {
			stream >> v;
		}
		for (int i = 0; i < u; i++) {
			stream >> v;
		}
		while (stream >> v) {
			if (v == c) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, int t, int u, int v, string s) {
		string w;
		for (int i = 0; i < n; i++) {
			stream >> w;
		}
		for (int i = 0; i < m; i++) {
			stream >> w;
		}
		for (int i = 0; i < o; i++) {
			stream >> w;
		}
		for (int i = 0; i < p; i++) {
			stream >> w;
		}
		for (int i = 0; i < q; i++) {
			stream >> w;
		}
		for (int i = 0; i < r; i++) {
			stream >> w;
		}
		for (int i = 0; i < s; i++) {
			stream >> w;
		}
		for (int i = 0; i < t; i++) {
			stream >> w;
		}
		for (int i = 0; i < u; i++) {
			stream >> w;
		}
		for (int i = 0; i < v; i++) {
			stream >> w;
		}
		while (stream >> w) {
			if (w == s) {
				return;
			}
		}
	}
	void ignoreUntil(int n, int m, int o, int p, int q, int r, int s, int t, int u, int v, char c) {
		string w;
		for (int i = 0; i < n; i++) {
			stream >> w;
		}
		for (int i = 0; i < m; i++) {
			stream >> w;
		}
		for (int i = 0; i < o; i++) {
			stream >> w;
		}
		for (int i = 0; i < p; i++) {
			stream >> w;
		}
		for (int i = 0; i < q; i++) {
			stream >> w;
		}
		for (int i = 0; i < r; i++) {
			stream >> w;
		}
		for (int i = 0; i < s; i++) {
			stream >> w;
		}
		for (int i = 0; i < t; i++) {
			stream >> w;
		}
		for (int i = 0; i < u; i++) 