#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Main {
    int N;
    long MOD = 1000000007L;
    string TOKENS[4] = { "A", "C", "G", "T" };
    unordered_map<string, long> memo[1001]; // Assuming N will not exceed 1000

public:
    Main() {
        cin >> N; // Reading the number of test cases
    }

    long calc() {
        return dfs(0, "TTT"); // Calling the recursive function to calculate the result
    }

    // Checking if the last 4 nucleotides form an invalid sequence
    bool isOK(const string& last4) {
        if (last4.find("AGC") != string::npos) { // If the sequence contains "AGC", it's invalid
            return false;
        }

        for (int i = 0; i < 3; ++i) { // Checking all possible pairs of adjacent nucleotides
            string s = last4;
            swap(s[i], s[i + 1]); // Swapping adjacent nucleotides

            if (s.find("AGC") != string::npos) { // If the pair contains "AGC", it's invalid
                return false;
            }
        }

        return true; // If no invalid sequence is found, the last 4 nucleotides are valid
    }

    long dfs(int current, const string& last3) {
        if (memo[current].count(last3)) { // If the result for the current sub-sequence and last 3 nucleotides is already calculated
            return memo[current][last3];
        }

        if (current == N) { // If we reach the end of the sequence, the result is 1
            return 1;
        }

        long result = 0; // Initializing the result to 0

        for (const string& c : TOKENS) { // Iterating through all possible next nucleotides
            if (isOK(last3 + c)) { // If the next nucleotide and the current sequence form a valid sequence
                result = (result + dfs(current + 1, last3.substr(1) + c)) % MOD; // Recursively calculating the result for the next sub-sequence
            }
        }

        memo[current][last3] = result; // Storing the result for the current sub-sequence and last 3 nucleotides
        return result; // Returning the result
    }
};

int main() {
    Main ins; // Creating an instance of the Main class
    cout << ins.calc() << endl; // Printing the result
    return 0;
}

// <END-OF-CODE>
