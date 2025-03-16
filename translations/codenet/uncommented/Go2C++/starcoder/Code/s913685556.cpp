#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int main() {
	Scanner sc;
	int A, B;
	A = sc.NextInt();
	B = sc.NextInt();

	int mx = max(A+B, A-B);
	mx = max(mx, A*B);
	cout << mx << endl;
}

int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

class Scanner {
public:
	Scanner() {
		r = new bufio::Reader();
	}
	~Scanner() {
		delete r;
	}
	string Next() {
		pre();
		start = p;
		while (p < buf.size() && buf[p]!='') {
			p++;
		}
		string result = string(buf.begin() + start, buf.begin() + p);
		p++;
		return result;
	}
	string NextLine() {
		pre();
		start = p;
		p = buf.size();
		return string(buf.begin() + start, buf.end());
	}
	int NextInt() {
		int v;
		stringstream ss(Next());
		ss >> v;
		return v;
	}
	int64_t NextInt64() {
		int64_t v;
		stringstream ss(Next());
		ss >> v;
		return v;
	}
	double NextFloat() {
		double v;
		stringstream ss(Next());
		ss >> v;
		return v;
	}
	vector<int> NextIntArray() {
		pre();
		start = p;
		vector<int> result;
		while (p < buf.size() + 1 && buf[p]!='') {
			if (p == buf.size()) {
				int v;
				stringstream ss(string(buf.begin() + start, buf.end()));
				ss >> v;
				result.push_back(v);
				break;
			}
			p++;
		}
		return result;
	}
	vector<int64_t> NextInt64Array() {
		pre();
		start = p;
		vector<int64_t> result;
		while (p < buf.size() + 1 && buf[p]!='') {
			if (p == buf.size()) {
				int64_t v;
				stringstream ss(string(buf.begin() + start, buf.end()));
				ss >> v;
				result.push_back(v);
				break;
			}
			p++;
		}
		return result;
	}
	map<int, bool> NextMap() {
		pre();
		start = p;
		map<int, bool> mp;
		while (p < buf.size()) {
			if (buf[p] =='') {
				int v;
				stringstream ss(string(buf.begin() + start, buf.begin() + p));
				ss >> v;
				mp[v] = true;
				start = p + 1;
			}
			p++;
		}
		int v;
		stringstream ss(string(buf.begin() + start, buf.begin() + p));
		ss >> v;
		mp[v] = true;
		return mp;
	}
private:
	void pre() {
		if (p >= buf.size()) {
			readLine();
			p = 0;
		}
	}
	void readLine() {
		buf.clear();
		while (true) {
			string l;
			bool p;
			tie(l, p) = r->ReadLine();
			buf.insert(buf.end(), l.begin(), l.end());
			if (!p) {
				break;
			}
		}
	}
	bufio::Reader *r;
	vector<char> buf;
	int p = 0;
	int start = 0;
};

