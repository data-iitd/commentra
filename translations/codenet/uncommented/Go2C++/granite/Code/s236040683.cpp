
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

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
        cout << n[i].size() << endl;
    }

    return 0;
}

