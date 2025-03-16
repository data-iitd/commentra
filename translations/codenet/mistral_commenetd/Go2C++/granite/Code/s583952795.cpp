
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int initialBufSize = 1e4;
const int maxBufSize = 1e8;

vector<string> split(string s) {
    vector<string> ret;
    stringstream ss(s);
    string item;
    while (getline(ss, item,'')) {
        ret.push_back(item);
    }
    return ret;
}

int main() {
    vector<char> buf(initialBufSize);
    cin.rdbuf()->pubsetbuf(&buf[0], maxBufSize);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    string s;
    int tmp = N;
    while (tmp > 0) {
        s = to_string(tmp % K) + s;
        tmp /= K;
    }

    cout << s.length() << endl;

    return 0;
}

