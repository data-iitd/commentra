#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void out(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> n(N);
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        n[from].push_back(to);
        n[to].push_back(from);
    }

    for (int i = 0; i < N; i++) {
        cout << n[i].size() << endl;
    }

    return 0;
}
