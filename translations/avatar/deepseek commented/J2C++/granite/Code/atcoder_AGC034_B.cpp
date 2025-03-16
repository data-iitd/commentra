

#include <iostream>
#include <string>
using namespace std;

class BABC {
public:
    void solve(int testNumber, string s) {
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
        cout << cnt << endl;
    }
};

int main() {
    string s;
    cin >> s;
    BABC solver;
    solver.solve(1, s);
    return 0;
}
// The BABC class contains the logic to solve the problem. The solve method implements the main logic.

