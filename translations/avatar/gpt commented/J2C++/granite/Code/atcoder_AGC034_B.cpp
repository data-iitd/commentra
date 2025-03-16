
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class BABC {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        string s;
        in >> s;
        regex pattern("BC");
        s = regex_replace(s, pattern, "D");
        long long cnt = 0;
        long long tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                tmp++;
            } else if (s[i] == 'D') {
                cnt += tmp;
            } else {
                tmp = 0;
            }
        }
        out << cnt << endl;
    }
};

int main() {
    BABC solver;
    solver.solve(1, cin, cout);
    return 0;
}

