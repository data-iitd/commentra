#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string arr;
    getline(cin, arr);
    int N = arr.length();
    unordered_set<string> set;
    int K;
    cin >> K;
    cin.ignore(); // To ignore the newline after reading K
    int res = 0;

    for (int k = 0; k < K; k++) {
        string input;
        getline(cin, input);
        int a = 0, b = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) {
                a++;
            } else if (arr[i] == input[1]) {
                b++;
            } else {
                res += min(a, b);
                a = b = 0;
            }
        }
        res += min(a, b);
    }

    cout << res << endl;

    return 0;
}
