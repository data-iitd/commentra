
#include <iostream>
#include <map>
#include <string>

using namespace std;

const long MOD = 1000000007L;
const string TOKENS[4] = {"A", "C", "G", "T"};

long dfs(int current, string last3, map<string, long> &memo) {
    if (memo.find(last3)!= memo.end()) {
        return memo[last3];
    }
    if (current == N) {
        return 1;
    }
    long result = 0;
    for (string c : TOKENS) {
        if (isOK(last3 + c)) {
            result = (result + dfs(current + 1, last3.substr(1, last3.length()) + c, memo)) % MOD;
        }
    }
    memo[last3] = result;
    return result;
}

bool isOK(string last4) {
    if (last4.find("AGC")!= string::npos) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        char vals[4];
        for (int j = 0; j < 4; j++) {
            vals[j] = last4[j];
        }
        vals[i] = last4[i + 1];
        vals[i + 1] = last4[i];
        string s(vals);
        if (s.find("AGC")!= string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    map<string, long> memo;
    cout << dfs(0, "TTT", memo) << endl;
    return 0;
}

