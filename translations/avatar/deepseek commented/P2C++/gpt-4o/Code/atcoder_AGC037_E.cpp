#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string get_last_dict(const string& s_str, int N);
bool check_normal_dict(const string& u, int pointer1, int pointer2, int N);

int main() {
    int N, K;
    cin >> N >> K; // Read the values of N and K from input
    string S;
    cin >> S; // Read the string S from input

    bool aaaa = false; // Initialize a flag to check special conditions
    if (K >= 15) {
        aaaa = true; // If K is 15 or more, set the flag to True
    } else if ((1 << K) >= N) {
        aaaa = true; // If 2 to the power of K is greater than or equal to N, set the flag to True
    }

    if (aaaa) {
        cout << string(N, *min_element(S.begin(), S.end())) << endl; // Print the minimum character in S multiplied by N
        return 0; // Exit
    }

    S = get_last_dict(S, N); // Transform the string S using the get_last_dict function

    if (K == 1) {
        cout << S << endl; // If K is 1, print the transformed S
    } else {
        int count = 0;
        for (char c : S) {
            if (c == S[0]) {
                count++; // Count the number of times the first character appears in S
            } else {
                break;
            }
        }

        if (count * (1 << (K - 1)) >= N) {
            cout << string(N, S[0]) << endl; // If repeating the first character a certain number of times exceeds the length of S, print the first character repeated N times
        } else {
            S = string(count * ((1 << (K - 1)) - 1), S[0]) + S; // Construct a new string by repeating the first character and appending the original S
            cout << S.substr(0, N) << endl; // Print the first N characters of the new string
        }
    }

    return 0;
}

string get_last_dict(const string& s_str, int N) {
    string U = s_str + string(s_str.rbegin(), s_str.rend()); // Concatenate the string with its reverse
    char c = *min_element(s_str.begin(), s_str.end()); // Find the minimum character in the original string
    size_t p = U.find(c); // Find the index of the minimum character in the concatenated string
    size_t minindex = p;
    p++;

    while (p <= N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p, N)) {
                minindex = p;
            }
        }
        p++;
    }
    return U.substr(minindex, N); // Find the lexicographically smallest substring of length N
}

bool check_normal_dict(const string& u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return true;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return false;
        }
    }
    return false;
    // Compare two substrings to determine which one is lexicographically smaller
}

// <END-OF-CODE>
