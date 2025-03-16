
#include <bits/stdc++.h>
using namespace std;

class Main {
private:
    int cal(string s, char c) {
        int n = s.length();
        int m = n - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c && (m & i) == i) {
                ans ^= 1;
            }
        }
        return ans;
    }

public:
    void solve() {
        int n = scanf("%d", &n);
        char s[n];
        scanf("%s", s);
        string sb;
        for (int i = 1; i < n; i++) {
            sb.push_back(abs(s[i] - s[i - 1]));
        }
        if (n == 2) {
            printf("%c\n", sb[0]);
            return;
        }
        string s2 = sb;
        if (s2.find('1')!= string::npos) {
            printf("%d\n", cal(s2, '1'));
        } else {
            printf("%d\n", cal(s2, '2') * 2);
        }
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// END-OF-CODE