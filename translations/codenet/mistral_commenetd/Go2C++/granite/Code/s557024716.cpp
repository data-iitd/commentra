
/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

#include <bits/stdc++.h>
using namespace std;

/********** FAU standard libraries **********/

//cout << bitset<32>(MAX) << endl; 	// binary expression

/********** I/O usage **********/

//string str = ReadString();
//int i = ReadInt();
//vector<int> X = ReadIntVec(n);
//vector<char> S = ReadCharVec();
//double d = ReadDouble();
//vector<double> A = ReadDoubleVec(n);

//string str = ZeroPaddingInt(num, 32);
//str = PrintIntsLine(X...);

/*******************************************************************/

const int MOD = 1000000000 + 7;
//const int MOD = 998244353;
const int ALPHABET_NUM = 26;
const long long INF_LL = 1e18;
const int INF_INT = 1e9;
const long long NIL = -1;

// for dijkstra, prim, and so on
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int main() {
    // Read input values
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;

    // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
    vector<vector<int>> patterns = DuplicatePatterns({0, 1, 2, 3}, k);

    // Check each generated pattern
    for (const auto& P : patterns) {
        // Apply bitwise operation to RGB values of the given input
        int r = a, g = b, b_ = c;
        for (int i = 0; i < P.size(); i++) {
            if (P[i] == 0) {
                continue;
            } else if (P[i] == 1) {
                r *= 2;
            } else if (P[i] == 2) {
                g *= 2;
            } else if (P[i] == 3) {
                b_ *= 2;
            }
        }

        // Check if the result satisfies the condition g > r and b_ > g
        if (g > r && b_ > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // If all patterns are checked and no satisfying pattern is found, print "No"
    cout << "No" << endl;

    return 0;
}

// DuplicatePatterns returns all patterns of n^k of elems([]int).
vector<vector<int>> DuplicatePatterns(vector<int> elems, int k) {
    return dupliRec({}, elems, k);
}

// DFS function for DuplicatePatterns.
vector<vector<int>> dupliRec(vector<int> pattern, vector<int> elems, int k) {
    if (pattern.size() == k) {
        // Return the generated pattern as a vector of vectors
        return {pattern};
    }

    vector<vector<int>> res;
    for (const auto& e : elems) {
        // Create a new pattern by appending the current element to the current pattern
        vector<int> newPattern = pattern;
        newPattern.push_back(e);

        // Recursively call the function with the new pattern and the remaining elements
        auto subPatterns = dupliRec(newPattern, elems, k);

        // Append the sub-patterns to the result
        res.insert(res.end(), subPatterns.begin(), subPatterns.end());
    }

    return res;
}

// Translate the above C++ code to Java and end with comment "