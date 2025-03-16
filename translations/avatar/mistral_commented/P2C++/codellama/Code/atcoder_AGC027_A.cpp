
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> na() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> a;
    int x;
    while (ss >> x) {
        a.push_back(x);
    }
    return a;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a = na();
    sort(a.begin(), a.end());
    int ans = 0;
    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }
    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans++;
    }
    if (x != 0) {
        ans--;
    }
    cout << ans << endl;
    return 0;
}

