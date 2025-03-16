#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
#include <tuple>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // To ignore the newline after the integer input
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, S[i]);
    }

    vector<int> march_lis(5, 0);
    string march = "MARCH";

    for (const string& s : S) {
        char first_char = toupper(s[0]);
        size_t index = march.find(first_char);
        if (index != string::npos) {
            march_lis[index]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
