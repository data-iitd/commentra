
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Block {
    string value;
    int len;
};

vector<Block> RunLength(string s) {
    vector<Block> r;
    if (s.length() == 0) {
        return r;
    }
    Block t = {s[0], 1};
    for (int i = 1; i < s.length(); i++) {
        if (t.value == s[i]) {
            t.len++;
        } else {
            r.push_back(t);
            t = {s[i], 1};
        }
    }
    r.push_back(t);
    return r;
}

int main() {
    int N, K, ans = 0;
    string S;
    cin >> N >> K;
    cin >> S;
    vector<Block> blocks = RunLength(S);
    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < blocks.size(); r++) {
        sum += blocks[r].len;
        if (blocks[r].value == "0") {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].len;
            if (blocks[l].value == "0") {
                zero--;
            }
            l++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

