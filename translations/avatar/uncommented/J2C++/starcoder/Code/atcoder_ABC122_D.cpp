#include <bits/stdc++.h>
using namespace std;

int N;
long long MOD = 1000000007;
string TOKENS[] = {"A", "C", "G", "T"};
map<string, long long> memo[100001];

class Main {
public:
    Main() {
        cin >> N;
        for (int i = 0; i < memo.size(); ++i) {
            memo[i] = map<string, long long>();
        }
    }
    long long calc() {
        return dfs(0, "TTT");
    }
    bool isOK(string last4) {
        if (last4.find("AGC")!= string::npos) {
            return false;
        }
        for (int i = 0; i < 3; ++i) {
            char vals[4];
            strcpy(vals, last4.c_str());
            swap(vals[i], vals[i + 1]);
            string s(vals);
            if (s.find("AGC")!= string::npos) {
                return false;
            }
        }
        return true;
    }
    long long dfs(int current, string last3) {
        if (memo[current].find(last3)!= memo[current].end()) {
            return memo[current][last3];
        }
        if (current == N) {
            return 1;
        }
        long long result = 0;
        for (string c : TOKENS) {
            if (isOK(last3 + c)) {
                result = (result + dfs(current + 1, last3.substr(1, last3.length()) + c)) % MOD;
            }
        }
        memo[current][last3] = result;
        return result;
    }
};

int main() {
    Main ins;
    cout << ins.calc() << endl;
    return 0;
}

