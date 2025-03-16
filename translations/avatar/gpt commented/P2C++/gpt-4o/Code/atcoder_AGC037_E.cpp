#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to compare two rotations of the string
bool check_normal_dict(const string &u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return true;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return false;
        }
    }
    return false;
}

// Function to get the lexicographically smallest rotation of the string
string get_last_dict(const string &s_str) {
    int N = s_str.length();
    string U = s_str + string(s_str.rbegin(), s_str.rend());
    char c = *min_element(s_str.begin(), s_str.end());
    int p = U.find(c);
    int minindex = p;
    p += 1;

    while (p <= N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p, N)) {
                minindex = p;
            }
        }
        p++;
    }

    return U.substr(minindex, N);
}

int main() {
    // Read input values for N and K
    int N, K;
    cin >> N >> K;
    // Read the string S
    string S;
    cin >> S;

    // Initialize a flag to determine if we can use a shortcut for output
    bool aaaa = false;

    // Check if K is large enough or if 2^K is greater than or equal to N
    if (K >= 15) {
        aaaa = true;
    } else if ((1 << K) >= N) { // 2^K
        aaaa = true;
    }

    // If the shortcut condition is met, print the minimum character repeated N times and exit
    if (aaaa) {
        cout << string(N, *min_element(S.begin(), S.end())) << endl;
        return 0;
    }

    // Get the lexicographically smallest rotation of S
    S = get_last_dict(S);

    // If K is 1, simply print the smallest rotation
    if (K == 1) {
        cout << S << endl;
    } else {
        int count = 0;
        // Count how many times the first character appears consecutively
        for (char c : S) {
            if (c == S[0]) {
                count++;
            } else {
                break;
            }
        }

        // Check if the repeated character can fill the string of length N
        if (count * (1 << (K - 1)) >= N) { // 2^(K-1)
            cout << string(N, S[0]) << endl;
        } else {
            // Construct the output string based on the count and the original string
            S = string(count * ((1 << (K - 1)) - 1), S[0]) + S; // 2^(K-1) - 1
            // Print the first N characters of the constructed string
            cout << S.substr(0, N) << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
