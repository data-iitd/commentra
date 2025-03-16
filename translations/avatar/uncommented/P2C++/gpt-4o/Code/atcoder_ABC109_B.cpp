#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

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
    int i = -1;
    
    for (const auto& v : l) {
        s[v]++;
        if (s[v] >= 2) {
            f = "No";
        }
        if (i != -1 && l[i].back() != v[0]) {
            f = "No";
        }
        i++;
    }
    
    cout << f << endl;
    return 0;
}

// <END-OF-CODE>
