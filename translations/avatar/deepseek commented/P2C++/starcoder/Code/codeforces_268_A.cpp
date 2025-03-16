
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<string>> q;
    int count = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<string> v;
        v.push_back(s);
        q.push_back(v);
    }

    for (int j = 0; j < q.size(); j++) {
        for (int k = 0; k < q.size(); k++) {
            if (j == k) {
                continue;
            }
            if (q[j][0] == q[k][q[k].size() - 1]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

