#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string v;
    cin >> v;
    vector<string> a;
    bool f = k - 1 < n - k;
    int m = min(k - 1, n - k);
    for (int i = 0; i < m; i++) {
        a.push_back(f? "RIGHT" : "LEFT");
    }
    for (int i = 0; i < v.size(); i++) {
        a.push_back("PRINT " + v[i]);
        a.push_back(f? "LEFT" : "RIGHT");
    }
    for (int i = 0; i < a.size() - 1; i++) {
        cout << a[i] << endl;
    }
    return 0;
}

