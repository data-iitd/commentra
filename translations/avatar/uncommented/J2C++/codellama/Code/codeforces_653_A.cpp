
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        a.push_back(value);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    bool found = false;
    for (int i = 0; i < a.size() - 2; i++) {
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
            found = true;
        }
    }
    cout << (found ? "YES" : "NO") << endl;
    return 0;
}

