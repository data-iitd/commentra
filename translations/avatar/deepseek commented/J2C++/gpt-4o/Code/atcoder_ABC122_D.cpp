#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Main {
    int N;
    long MOD = 1000000007L;
    vector<string> TOKENS = { "A", "C", "G", "T" };
    vector<unordered_map<string, long>> memo;

public:
    // Constructor initializes N and sets up memoization array
    Main() {
        cin >> N;
        memo.resize(N + 1);
    }

    // Method to calculate the number of valid sequences
    long calc() {
        return dfs(0, "TTT");
    }

    // Method to check if the last four characters form a valid sequence
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

    // Recursive method to count valid sequences using memoization
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

    // Main method to run the program
    static int main() {
        Main ins;
        cout << ins.calc() << endl;
        return 0;
    }
};

// Entry point of the program
int main() {
    return Main::main();
}

// <END-OF-CODE>
