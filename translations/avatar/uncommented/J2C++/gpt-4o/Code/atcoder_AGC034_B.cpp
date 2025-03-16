#include <iostream>
#include <string>

using namespace std;

class BABC {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        string s;
        in >> s;
        // Replace "BC" with "D"
        size_t pos;
        while ((pos = s.find("BC")) != string::npos) {
            s.replace(pos, 2, "D");
        }

        long long cnt = 0;
        long long tmp = 0;
        for (char c : s) {
            if (c == 'A') {
                tmp++;
            } else if (c == 'D') {
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
    int testNumber = 1; // Assuming a single test case as in the Java code
    solver.solve(testNumber, cin, cout);
    return 0;
}

// <END-OF-CODE>
