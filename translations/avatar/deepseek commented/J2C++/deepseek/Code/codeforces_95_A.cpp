#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Main {
public:
    // Constructor to initialize the superclass with cout and auto-flush enabled
    Main() : out(cout), autoFlush(true) {}

    // Function to compare two character arrays up to a specified length, ignoring case
    int compare(const vector<char>& aa, int i, const vector<char>& bb, int j, int m) {
        while (m-- > 0) {
            char a = toupper(aa[i]);
            char b = toupper(bb[j]);
            if (a != b) return a - b;
            i++;
            j++;
        }
        return 0;
    }

    // Main logic of the program
    void main() {
        // Reading the number of strings and the array of strings
        int n;
        cin >> n;
        vector<vector<char>> ss(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ss[i] = vector<char>(s.begin(), s.end());
        }

        // Reading the pattern array and the target character
        string cc_str;
        cin >> cc_str;
        vector<char> cc(cc_str.begin(), cc_str.end());
        int m = cc.size();
        char c;
        cin >> c;
        char c_ = toupper(c);
        char a = c == 'a' ? 'b' : 'a';
        char a_ = toupper(a);

        // Array to mark positions in cc that match any string in ss
        vector<bool> lucky(m, false);

        // Finding lucky positions and updating characters based on the target character c
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int l = ss[i].size();
                if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) {
                    for (int h = 0; h < l; h++) {
                        lucky[j + h] = true;
                    }
                }
            }
        }

        // Updating characters in cc based on the lucky positions and target character c
        for (int j = 0; j < m; j++) {
            if (lucky[j]) {
                if (tolower(cc[j]) == c) {
                    cc[j] = isupper(cc[j]) ? a_ : a;
                } else {
                    cc[j] = isupper(cc[j]) ? c_ : c;
                }
            }
        }

        // Printing the modified cc array
        for (char ch : cc) {
            out << ch;
        }
        out << endl;
    }

private:
    ostream& out;
    bool autoFlush;
};

int main() {
    Main o;
    o.main();
    if (o.autoFlush) {
        cout.flush();
    }
    return 0;
}

