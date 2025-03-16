
#include <bits/stdc++.h>
using namespace std;

// Function out is used to print the output to the console
void out(vector<string> x) {
    for (auto i : x) {
        cout << i << endl;
    }
}

int main() {
    // Initialize vector of strings s with capacity N
    int N, L;
    cin >> N >> L;
    vector<string> s(N);

    // Read data points X from the input and store them in the vector s
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    // Print the number of data points N, number of queries L, and the vector s
    out({to_string(N), to_string(L), to_string(s)});

    // Sort the vector s in ascending order
    sort(s.begin(), s.end());

    // Initialize an empty string ans to store the concatenated X values
    string ans = "";

    // Iterate through the vector s and concatenate X values to the string ans
    for (int i = 0; i < N; i++) {
        ans += s[i];
    }

    // Print the concatenated string ans to the console
    cout << ans << endl;

    return 0;
}

