#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Main {
private:
    int N;
    const long long MOD = 1000000007LL;
    vector<string> TOKENS = {"A", "C", "G", "T"};
    vector<unordered_map<string, long long>> memo;

    // Constructor
    Main() {
        cin >> N; // Reading the number of test cases
        memo.resize(N + 1); // Initializing a 2D map to store the results of subproblems
    }

    // Checking if the last 4 nucleotides form an invalid sequence
    bool isOK(const string& last4) {
        if (last4.find("AGC") != string::npos) { // If the sequence contains "AGC", it's invalid
            return false;
        }

        for (int i = 0; i < 3; ++i) { // Checking all possible pairs of adjacent nucleotides
            string s = last4;
            swap(s[i], s[i + 1]); // Swap adjacent nucleotides
            if (s.find("AGC") != string::npos) { // If the swapped sequence contains "AGC", it's invalid
                return false;
            }
        }

        return true; // If no invalid sequence is found, the last 4 nucleotides are valid
    }

    long long dfs(int current, const string& last3) {
        if (memo[current].find(last3) != memo[current].end()) { // If the result for the current sub-sequence and last 3 nucleotides is already calculated
            return memo[current][last3];
        }

        if (current == N) { // If we reach the end of the sequence, the result is 1
            return 1;
        }

        long long result = 0; // Initializing the result to 0

        for (const string& c : TOKENS) { // Iterating through all possible next nucleotides
            if (isOK(last3 + c)) { // If the next nucleotide and the current sequence form a valid sequence
                result = (result + dfs(current + 1, last3.substr(1) + c)) % MOD; // Recursively calculating the result for the next sub-sequence
            }
        }

        memo[current][last3] = result; // Storing the result for the current sub-sequence and last 3 nucleotides
        return result; // Returning the result
    }

    long long calc() {
        return dfs(0, "TTT"); // Calling the recursive function to calculate the result
    }

public:
    static void main() {
        Main ins; // Creating an instance of the Main class
        cout << ins.calc() << endl; // Printing the result
    }
};

int main() {
    Main::main();
    return 0;
}

