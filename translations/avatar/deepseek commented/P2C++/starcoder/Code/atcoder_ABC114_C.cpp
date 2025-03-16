
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s == "753") ans++;
    }
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s == "753") ans += aaa(s);
    }
    cout << ans << endl;
    return 0;
}

int aaa(string n) {
    if (stoi(n) > N) return 0;
    int ans = 1;
    if (set<char>(n.begin(), n.end()) == set<char>({'7', '5', '3'})) ans = 1;
    for (int i = 0; i < 3; i++) {
        string s = n + "753"[i];
        ans += aaa(s);
    }
    return ans;
}

