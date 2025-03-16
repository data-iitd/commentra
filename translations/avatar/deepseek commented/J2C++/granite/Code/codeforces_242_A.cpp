

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int count = 0;
    vector<pair<int, int>> pairs;

    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue;
            count++;
            pairs.push_back(make_pair(i, j));
        }
    }

    cout << count << endl;

    for (auto pair : pairs) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}

