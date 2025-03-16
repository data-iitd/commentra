#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>

using namespace std;

bool Bipartite(const vector<string>& S) {
    int N = S.size();
    vector<int> D(N, 0);
    D[0] = 1;
    queue<int> Q;
    Q.push(0);
    bool ret = true;

    while (!Q.empty() && ret) {
        int q = Q.front();
        Q.pop();
        for (int j = 0; j < N; ++j) {
            if (S[q][j] == '0') {
                continue;
            }
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q.push(j);
            } else if (D[j] % 2 == D[q] % 2) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int WarshallFloyd(const vector<string>& S) {
    int N = S.size();
    vector<vector<int>> G(N, vector<int>(N, numeric_limits<int>::max()));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                G[i][j] = 0;
            } else if (S[i][j] == '1') {
                G[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] != numeric_limits<int>::max() && G[k][j] != numeric_limits<int>::max() && 
                    G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (ans < G[i][j] && G[i][j] != numeric_limits<int>::max()) {
                ans = G[i][j];
            }
        }
    }
    return ans + 1;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // To ignore the newline after the integer input
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, S[i]);
    }

    if (!Bipartite(S)) {
        cout << -1 << endl;
    } else {
        cout << WarshallFloyd(S) << endl;
    }

    return 0;
}
// <END-OF-CODE>
