
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Scanner {
public:
	Scanner() {
		r = new istream(cin.rdbuf());
		buf = new string();
		p = 0;
	}
	string Next() {
		pre();
		int start = p;
		for (; p < buf->size(); p++) {
			if ((*buf)[p] == ' ') {
				break;
			}
		}
		string result = (*buf).substr(start, p - start);
		p++;
		return result;
	}
	string NextLine() {
		pre();
		int start = p;
		p = buf->size();
		return (*buf).substr(start, p - start);
	}
	int NextInt() {
		return atoi(Next().c_str());
	}

	vector<int> NextIntArray() {
		pre();
		int start = p;
		vector<int> result;
		for (; p < buf->size(); p++) {
			if ((*buf)[p] == ' ') {
				int v = atoi((*buf).substr(start, p - start).c_str());
				result.push_back(v);
				start = p + 1;
			}
		}
		int v = atoi((*buf).substr(start, p - start).c_str());
		result.push_back(v);

		return result;
	}

	map<int, bool> NextMap() {
		pre();
		int start = p;
		map<int, bool> mp;
		for (; p < buf->size(); p++) {
			if ((*buf)[p] == ' ') {
				int v = atoi((*buf).substr(start, p - start).c_str());
				mp[v] = true;
				start = p + 1;
			}
		}
		int v = atoi((*buf).substr(start, p - start).c_str());
		mp[v] = true;

		return mp;
	}

	void pre() {
		if (p >= buf->size()) {
			readLine();
			p = 0;
		}
	}
	void readLine() {
		buf->clear();
		for (; ; ) {
			string line;
			getline(*r, line);
			*buf += line;
			if (!r->good()) {
				break;
			}
		}
	}

private:
	istream* r;
	string* buf;
	int p;
};

int main() {
	Scanner sc;

	int n = sc.NextInt();
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		double tmp = 1 / sc.NextInt();
		ans += tmp;
	}
	cout << 1 / ans << endl;

	return 0;
}

