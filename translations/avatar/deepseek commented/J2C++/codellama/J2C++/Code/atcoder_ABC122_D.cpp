#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std ; 

class Main {
    int N ; 
    long MOD = 1000000007L ; 
    vector<string> TOKENS = { "A", "C", "G", "T" } ; 
    map<string, long> memo[100001] ; 

    // Constructor initializes N and sets up memoization array
    Main() {
        cin >> N ; 
        for (int i = 0 ; i < 100001 ; ++i) {
            memo[i] = map<string, long>() ; 
        }
    }

    // Method to calculate the number of valid sequences
    long calc() {
        return dfs(0, "TTT") ; 
    }

    // Method to check if the last four characters form a valid sequence
    bool isOK(string last4) {
        if (last4.find("AGC") != string::npos) {
            return false ; 
        }
        for (int i = 0 ; i < 3 ; ++i) {
            string vals = last4.substr(i, 3) ; 
            vals[i] = last4[i + 1] ; 
            vals[i + 1] = last4[i] ; 
            if (vals.find("AGC") != string::npos) {
                return false ; 
            }
        }
        return true ; 
    }

    // Recursive method to count valid sequences using memoization
    long dfs(int current, string last3) {
        if (memo[current].find(last3) != memo[current].end()) {
            return memo[current][last3] ; 
        }
        if (current == N) {
            return 1 ; 
        }
        long result = 0 ; 
        for (string c : TOKENS) {
            if (isOK(last3 + c)) {
                result = (result + dfs(current + 1, last3.substr(1, last3.length()) + c)) % MOD ; 
            }
        }
        memo[current][last3] = result ; 
        return result ; 
    }

    // Main method to run the program
    public:
    static void main(string[] args) {
        Main ins = new Main() ; 
        cout << ins.calc() << endl ; 
    }
}

