#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Main {
    int N;
    long MOD = 1000000007L;
    string TOKENS[4] = { "A", "C", "G", "T" };
    unordered_map<string, long> memo[100]; // Assuming N <= 100

public:
    Main() {
        cin >> N;
    }

    long calc() {
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

    long dfs(int current, const string& last3) {
        if (memo[current].count(last3)) {
            return memo[current][last3];
        }
        if (current == N) {
            return 1;
        }
        long result = 0;
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

// <END-OF-CODE>
