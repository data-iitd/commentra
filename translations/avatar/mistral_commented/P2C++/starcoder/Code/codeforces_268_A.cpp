#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<string>> q;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        vector<string> b;
        for (int j = 0; j < a.length(); j++) {
            b.push_back(a[j]);
        }
        q.push_back(b);
    }
    int count = 0;
    for (int i = 0; i < q.size(); i++) {
        for (int j = 0; j < q.size(); j++) {
            if (i == j) {
                continue;
            }
            if (q[i][0] == q[j][q[j].size() - 1]) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

