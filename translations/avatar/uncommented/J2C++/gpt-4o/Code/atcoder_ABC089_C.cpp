#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TaskC {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        int n;
        in >> n;
        vector<long long> cnt(5, 0);

        for (int i = 0; i < n; ++i) {
            string str;
            in >> str;
            char firstChar = str[0];
            if (firstChar == 'M') {
                cnt[0]++;
            } else if (firstChar == 'A') {
                cnt[1]++;
            } else if (firstChar == 'R') {
                cnt[2]++;
            } else if (firstChar == 'C') {
                cnt[3]++;
            } else if (firstChar == 'H') {
                cnt[4]++;
            }
        }

        long long res = cnt[0] * cnt[1] * cnt[2] +
                        cnt[0] * cnt[1] * cnt[3] +
                        cnt[0] * cnt[1] * cnt[4] +
                        cnt[0] * cnt[2] * cnt[3] +
                        cnt[0] * cnt[2] * cnt[4] +
                        cnt[0] * cnt[3] * cnt[4] +
                        cnt[1] * cnt[2] * cnt[3] +
                        cnt[1] * cnt[2] * cnt[4] +
                        cnt[1] * cnt[3] * cnt[4] +
                        cnt[2] * cnt[3] * cnt[4];

        out << res << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testNumber = 1;
    TaskC solver;
    solver.solve(testNumber, cin, cout);
    
    return 0;
}

// <END-OF-CODE>
