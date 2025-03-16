
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
	}
	string next() {
		pre();
		int start = p;
		for (; p < buf.size(); p++) {
			if (buf[p] == ' ') {
				break;
			}
		}
		string result = buf.substr(start, p - start);
		p++;
		return result;
	}
	string nextLine() {
		pre();
		int start = p;
		p = buf.size();
		return buf.substr(start);
	}
	int nextInt() {
		return stoi(next());
	}
	vector<int> nextIntArray() {
		pre();
		int start = p;
		vector<int> result;
		for (; p < buf.size(); p++) {
			if (buf[p] == ' ') {
				int v = stoi(buf.substr(start, p - start));
				result.push_back(v);
				start = p + 1;
			}
		}
		int v = stoi(buf.substr(start, p - start));
		result.push_back(v);
		return result;
	}
	map<int, bool> nextMap() {
		pre();
		int start = p;
		map<int, bool> mp;
		for (; p < buf.size(); p++) {
			if (buf[p] == ' ') {
				int v = stoi(buf.substr(start, p - start));
				mp[v] = true;
				start = p + 1;
			}
		}
		int v = stoi(buf.substr(start, p - start));
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
		buf = "";
		while (true) {
			string l;
			getline(*r, l);
			buf += l;
			if (!r->good()) {
				break;
			}
		}
	}
	istream* r;
	string buf;
	int p;
};

int main() {
	Scanner sc; // Initialize a new Scanner instance

	int n = sc.nextInt(); // Read an integer n from the standard input
	double ans = 0.0; // Initialize a variable ans to 0.0
	for (int i = 0; i < n; i++) { // Enter a loop that runs n times
		double tmp = 1 / (double)sc.nextInt(); // Read an integer, convert it to a double, and divide 1 by this value
		ans += tmp; // Add this result to ans
	}
	cout << 1 / ans << endl; // Calculate the reciprocal of ans and print it

	return 0;
}

