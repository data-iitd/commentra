#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Main {
public:
    int N;
    long long MOD = 1000000007;
    string TOKENS[4] = {"A", "C", "G", "T"};
    map<string, long long> memo[1000001];

    // Constructor initializes N and sets up memoization array
    Main() {
        cin >> N;
        for (int i = 0; i < 1000001; ++i) {
            memo[i] = map<string, long long>();
        }
    }

    // Method to calculate the number of valid sequences
    long long calc() {
        return dfs(0, "TTT");
    }

    // Method to check if the last four characters form a valid sequence
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

    // Recursive method to count valid sequences using memoization
    long long dfs(int current, string last3) {
        if (memo[current].find(last3)!= memo[current].end()) {
            return memo[current][last3];
        }
        if (current == N) {
            return 1;
        }
        long long result = 0;
        for (int i = 0; i < 4; ++i) {
            string c = TOKENS[i];
            if (isOK(last3 + c)) {
                result = (result + dfs(current + 1, last3.substr(1, last3.length() - 1) + c)) % MOD;
            }
        }
        memo[current][last3] = result;
        return result;
    }

    // Main method to run the program
    int main() {
        Main ins;
        cout << ins.calc() << endl;
        return 0;
    }
};

// 