#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

class Scanner {
public:
	Scanner(istream &in) : in(in) {}
	string Next() {
		while (isspace(in.peek())) in.get();
		string ret;
		while (!isspace(in.peek())) ret += in.get();
		return ret;
	}
	int NextInt() {
		return atoi(Next().c_str());
	}
	vector<int> NextIntArray() {
		vector<int> ret;
		while (isspace(in.peek())) in.get();
		string tmp;
		while (!isspace(in.peek())) {
			tmp += in.get();
		}
		istringstream iss(tmp);
		int x;
		while (iss >> x) ret.push_back(x);
		return ret;
	}
	map<int, bool> NextMap() {
		map<int, bool> ret;
		while (isspace(in.peek())) in.get();
		string tmp;
		while (!isspace(in.peek())) {
			tmp += in.get();
		}
		istringstream iss(tmp);
		int x;
		while (iss >> x) ret[x] = true;
		return ret;
	}
private:
	istream &in;
};

int main() {
	Scanner sc(cin);
	int n = sc.NextInt();
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		int tmp = sc.NextInt();
		ans += 1.0 / tmp;
	}
	cout << 1.0 / ans << endl;
	return 0;
}

