#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> s;
    vector<string> l(n);

    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    string f = "Yes";

    for (const auto& v : l) {
        s[v]++;

        if (s[v] >= 2) {
            f = "No";
        }
    }

    int i = -1;
    for (const auto& v : l) {
        if (i != -1 && l[i].back() != v[0]) {
            f = "No";
        }
        i++;
    }

    cout << f << endl;

    return 0;
}

