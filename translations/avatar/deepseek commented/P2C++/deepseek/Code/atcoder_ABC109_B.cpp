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
    string f = "Yes";
    int i = -1;

    for (string& v : l) {
        cin >> v;
        s[v] += 1;
        if (s[v] >= 2) {
            f = "No";
        }
        if (i != -1 && l[i].back() != v.front()) {
            f = "No";
        }
        i += 1;
    }

    cout << f << endl;
    return 0;
}

