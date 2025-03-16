#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> readInputLines(int N) {
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, S[i]);
    }
    return S;
}

bool isBipartite(const vector<string>& S) {
    int N = S.size();
    vector<int> D(N, 0);
    vector<int> Q(N);
    int pos = 0;
    Q[pos++] = 0;
    D[0] = 1;
    bool ret = true;

    for (int i = 0; i < N && ret; ++i) {
        int q = Q[i];
        for (int j = 0; j < N; ++j) {
            if (S[q][j] == '0') continue;
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q[pos++] = j;
            } else if (D[j] % 2 == D[q] % 2) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int warshallFloyd(const vector<string>& S) {
    int N = S.size();
    vector<vector<int>> G(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (S[i][j] == '0') {
                G[i][j] = N;
            } else {
                G[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (ans < G[i][j]) {
                ans = G[i][j];
            }
        }
    }
    return ans + 1;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // To ignore the newline character after N
    vector<string> S = readInputLines(N);
    if (!isBipartite(S)) {
        cout << -1 << endl;
    } else {
        cout << warshallFloyd(S) << endl;
    }
    return 0;
}
