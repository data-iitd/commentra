#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> s;
    string f = "Yes";
    int i = -1;
    for (int j = 0; j < n; j++) {
        string v;
        cin >> v;
        s[v]++;
        if (s[v] >= 2) {
            f = "No";
        }
        if (i != -1 && l[i][l[i].length() - 1] != v[0]) {
            f = "No";
        }
        i++;
    }
    cout << f << endl;
    return 0;
}

