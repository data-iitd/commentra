#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Main {
public:
    Main() {
        // Constructor implementation
    }

    int compare(const char* aa, int i, const char* bb, int j, int m) {
        while (m-- > 0) {
            char a = toupper(aa[i]);
            char b = toupper(bb[j]);
            if (a != b) return a - b;
            i++;
            j++;
        }
        return 0;
    }

    void main() {
        int n;
        cin >> n;
        vector<string> ss(n);
        for (int i = 0; i < n; i++) {
            cin >> ss[i];
        }
        string cc;
        cin >> cc;
        int m = cc.length();
        char c = cc[0];
        char c_ = toupper(c);
        char a = c == 'a' ? 'b' : 'a';
        char a_ = toupper(a);
        vector<bool> lucky(m, false);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int l = ss[i].length();
                if (m - j >= l && compare(cc.c_str(), j, ss[i].c_str(), 0, l) == 0) {
                    for (int h = 0; h < l; h++) {
                        lucky[j + h] = true;
                    }
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (lucky[j]) {
                if (tolower(cc[j]) == c) {
                    cc[j] = isupper(cc[j]) ? a_ : a;
                } else {
                    cc[j] = isupper(cc[j]) ? c_ : c;
                }
            }
        }
        cout << cc << endl;
    }
};

int main() {
    Main o;
    o.main();
    return 0;
}

