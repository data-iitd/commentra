
#include <iostream>
#include <map>
#include <string>
using namespace std;

const int MOD = 1000000007;
const string TOKENS[4] = {"A", "C", "G", "T"};
map<string, long> memo[100001];

long dfs(int current, string last3) {
    if (memo[current].count(last3) > 0) {
        return memo[current][last3];
    }
    if (current == N) {
        return 1;
    }
    long result = 0;
    for (string c : TOKENS) {
        if (isOK(last3 + c)) {
            result = (result + dfs(current + 1, last3.substr(1) + c)) % MOD;
        }
    }
    memo[current][last3] = result;
    return result;
}

bool isOK(string last4) {
    if (last4.find("AGC")!= string::npos) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        string vals = last4;
        swap(vals[i], vals[i + 1]);
        if (vals.find("AGC")!= string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    cout << dfs(0, "TTT") << endl;
    return 0;
}
// 