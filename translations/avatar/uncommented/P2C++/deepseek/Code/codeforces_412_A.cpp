#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string v;
    cin >> v;
    vector<string> d = {"LEFT", "RIGHT"};
    bool f = k - 1 < n - k;
    int m = min(k - 1, n - k);
    vector<string> a;
    for (int i = 0; i < m; i++) {
        a.push_back(d[!f]);
    }
    for (char i : v) {
        a.push_back("PRINT " + string(1, i));
        a.push_back(d[f]);
    }
    for (int i = 0; i < a.size() - 1; i++) {
        cout << a[i] << endl;
    }
    return 0;
}

