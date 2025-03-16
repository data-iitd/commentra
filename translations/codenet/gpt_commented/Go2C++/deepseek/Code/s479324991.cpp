#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

class Scanner {
public:
	Scanner() : buffer(istream_iterator<string>(cin), istream_iterator<string>()) {}

	int nextInt() {
		return stoi(next());
	}

	vector<int> nextIntArray() {
		vector<int> result;
		string token;
		while (getline(cin, token, ' ')) {
			result.push_back(stoi(token));
		}
		return result;
	}

private:
	vector<string> buffer;

	string next() {
		if (index >= buffer.size()) {
			cin.ignore();
			getline(cin, currentLine);
			istringstream lineStream(currentLine);
			buffer = vector<string>(istream_iterator<string>(lineStream), istream_iterator<string>());
			index = 0;
		}
		return buffer[index++];
	}

	int index = 0;
	string currentLine;
};

int main() {
	Scanner sc;
	int n = sc.nextInt();
	vector<double> arr(n);

	for (int i = 0; i < n; i++) {
		arr[i] = sc.nextInt();
	}

	sort(arr.begin(), arr.end());

	double prev = arr[0];

	for (int i = 1; i < n; i++) {
		prev = (prev + arr[i]) / 2;
	}

	cout << fixed << setprecision(10) << prev << endl;

	return 0;
}
