#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Main {
    int N;
    const long long MOD = 1000000007LL;
    vector<string> TOKENS = {"A", "C", "G", "T"};
    vector<unordered_map<string, long long>> memo;

public:
    Main() {
        cin >> N;
        memo.resize(N + 1);
    }

    long long calc() {
        return dfs(0, "TTT");
    }

    bool isOK(const string& last4) {
        if (last4.find("AGC") != string::npos) {
            return false;
        }
        for (int i = 0; i < 3; ++i) {
            string s = last4;
            swap(s[i], s[i + 1]);
            if (s.find("AGC") != string::npos) {
                return false;
            }
        }
        return true;
    }

    long long dfs(int current, const string& last3) {
        if (memo[current].find(last3) != memo[current].end()) {
            return memo[current][last3];
        }
        if (current == N) {
            return 1;
        }
        long long result = 0;
        for (const string& c : TOKENS) {
            if (isOK(last3 + c)) {
                result = (result + dfs(current + 1, last3.substr(1) + c)) % MOD;
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

