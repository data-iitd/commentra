#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Block {
    string Value;
    int Len;
};

vector<Block> RunLength(const string& s) {
    if (s.empty()) {
        return {};
    }

    Block t = {string(1, s[0]), 1};
    vector<Block> r;

    for (size_t i = 1; i < s.size(); ++i) {
        if (t.Value == string(1, s[i])) {
            t.Len++;
        } else {
            r.push_back(t);
            t = {string(1, s[i]), 1};
        }
    }

    r.push_back(t);
    return r;
}

int Max(int a, int b) {
    return b > a ? b : a;
}

int main() {
    int N, K, ans = 0;
    cin >> N >> K;

    string S;
    cin.ignore(); // To ignore the newline character after reading N and K
    getline(cin, S);

    vector<Block> blocks = RunLength(S);

    int sum = 0, zero = 0, l = 0;

    for (size_t r = 0; r < blocks.size(); ++r) {
        sum += blocks[r].Len;

        if (blocks[r].Value == "0") {
            zero++;
        }

        while (K < zero) {
            sum -= blocks[l].Len;
            if (blocks[l].Value == "0") {
                zero--;
            }
            l++;
        }

        ans = Max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}

