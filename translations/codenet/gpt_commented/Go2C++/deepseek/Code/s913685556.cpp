#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Scanner {
private:
	istream& in;
	string buffer;
	size_t pos;

	void pre() {
		if (pos >= buffer.size()) {
			buffer.clear();
			getline(in, buffer);
			pos = 0;
		}
	}

public:
	Scanner(istream& is = cin) : in(is), pos(0) {}

	string next() {
		pre();
		size_t start = pos;
		while (pos < buffer.size() && buffer[pos] != ' ') {
			pos++;
		}
		string result = buffer.substr(start, pos - start);
		pos++; // Skip the space
		return result;
	}

	int nextInt() {
		return stoi(next());
	}

	long long nextInt64() {
		return stoll(next());
	}

	double nextFloat() {
		return stod(next());
	}

	vector<int> nextIntArray() {
		pre();
		vector<int> result;
		size_t start = pos;
		while (pos < buffer.size() && buffer[pos] != ' ') {
			pos++;
		}
		string token = buffer.substr(start, pos - start);
		stringstream ss(token);
		int num;
		while (ss >> num) {
			result.push_back(num);
		}
		pos++; // Skip the space
		return result;
	}

	vector<long long> nextInt64Array() {
		pre();
		vector<long long> result;
		size_t start = pos;
		while (pos < buffer.size() && buffer[pos] != ' ') {
			pos++;
		}
		string token = buffer.substr(start, pos - start);
		stringstream ss(token);
		long long num;
		while (ss >> num) {
			result.push_back(num);
		}
		pos++; // Skip the space
		return result;
	}

	vector<pair<int, bool>> nextMap() {
		pre();
		vector<pair<int, bool>> result;
		size_t start = pos;
		while (pos < buffer.size() && buffer[pos] != ' ') {
			pos++;
		}
		string token = buffer.substr(start, pos - start);
		stringstream ss(token);
		int num;
		while (ss >> num) {
			result.push_back({num, true});
		}
		pos++; // Skip the space
		return result;
	}
};

int max(int a, int b) {
	return a < b ? b : a;
}

int main() {
	Scanner sc;
	int A = sc.nextInt(), B = sc.nextInt();
	int mx = max(A + B, max(A - B, A * B));
	cout << mx << endl;
	return 0;
}
