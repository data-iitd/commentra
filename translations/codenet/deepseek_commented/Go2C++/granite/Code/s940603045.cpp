
#include <bits/stdc++.h>
using namespace std;

const string abcd = "abcdefghijklmnopqrstuvwxyz";
const string ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int inf = numeric_limits<int>::max();

int main() {
    string N;
    cin >> N;
    int n = 0;
    for (char c : N) {
        n += c - '0';
    }
    int m = stoi(N);
    if (m % n == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

