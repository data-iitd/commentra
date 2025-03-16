#include <iostream>
#include <vector>

using namespace std;

void out(int x) {
    cout << x << endl;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> n(N);

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        n[from - 1].push_back(to - 1);
        n[to - 1].push_back(from - 1);
    }

    for (int i = 0; i < N; i++) {
        out(n[i].size());
    }

    return 0;
}

// <END-OF-CODE>
