#include <bits/stdc++.h>

using namespace std;

// I/O
struct Reader {
	FILE* fp;
	char buf[1 << 15], *p, *end;
	Reader() {
		fp = fopen("codejam/test_files/Y14R5P1/A.in", "r");
		p = buf;
		end = buf + fread(buf, 1, 1 << 15, fp);
	}
	~Reader() {
		fclose(fp);
	}
	char read() {
		if (p == end) {
			p = buf;
			end = buf + fread(buf, 1, 1 << 15, fp);
			if (end == p) return EOF;
		}
		return *p++;
	}
	void skip() {
		read();
		while (p < end && *p <= 32) p++;
	}
	int nextInt() {
		int x = 0;
		bool neg = 0;
		skip();
		if (*p == '-') neg = 1, p++;
		else if (*p == '+') p++;
		while (p < end && *p >= '0' && *p <= '9') x = x*10 + *p++ - '0';
		return neg? -x : x;
	}
	long long nextLongLong() {
		long long x = 0;
		bool neg = 0;
		skip();
		if (*p == '-') neg = 1, p++;
		else if (*p == '+') p++;
		while (p < end && *p >= '0' && *p <= '9') x = x*10 + *p++ - '0';
		return neg? -x : x;
	}
	double nextDouble() {
		double x = 0, div = 1;
		bool neg = 0;
		skip();
		if (*p == '-') neg = 1, p++;
		else if (*p == '+') p++;
		while (p < end && *p >= '0' && *p <= '9') x = x*10 + *p++ - '0', div *= 10;
		if (*p == '.') {
			p++;
			double d = 10;
			while (p < end && *p >= '0' && *p <= '9') x += (*p++ - '0') / d, d *= 10;
		}
		return neg? -x/div : x/div;
	}
	char* nextString() {
		char* s = p;
		while (p < end && *p > 32) p++;
		return s;
	}
	bool hasNext() {
		skip();
		return p < end;
	}
} reader;

// Arithmetic
#define MOD 1000000007
#define INF 1000000000000000000LL

int max(int a, int b) {
	return a > b? a : b;
}

int min(int a, int b) {
	return a < b? a : b;
}

int abs(int x) {
	return x < 0? -x : x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) res *= x;
	return res;
}

int ceil(int a, int b) {
	return (a + b - 1) / b;
}

// Sort
struct RuneSlice {
	vector<int> v;
	RuneSlice() {}
	RuneSlice(const string& s) {
		for (int i = 0; i < (int)s.size(); i++) v.push_back(s[i]);
	}
	int Len() { return (int)v.size(); }
	bool Less(int i, int j) { return v[i] < v[j]; }
	void Swap(int i, int j) { swap(v[i], v[j]); }
};

// Main
int main() {
	int N, D, A;
	N = reader.nextInt();
	D = reader.nextInt();
	A = reader.nextInt();
	vector<pair<int, int> > M(N);
	for (int i = 0; i < N; i++) {
		M[i].first = reader.nextInt();
		M[i].second = reader.nextInt();
	}
	sort(M.begin(), M.end());
	int ans = 0, total = 0;
	for (int i = 0; i < N; i++) {
		int x = M[i].first, h = M[i].second;
		while (!M.empty() && M.front().first < x) {
			total -= M.front().second;
			M.erase(M.begin());
		}
		if (total < h) {
			h -= total;
			int count = ceil(h, A);
			ans += count;
			total += count * A;
			M.push_back(make_pair(x + 2 * D, count * A));
		}
	}
	printf("%d\n", ans);
	return 0;
}

