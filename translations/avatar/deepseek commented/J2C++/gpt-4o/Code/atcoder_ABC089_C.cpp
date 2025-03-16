#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TaskC {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        int n;
        in >> n;
        vector<long long> cnt(5, 0);
        // Read the number of strings and initialize the count array.

        for (int i = 0; i < n; ++i) {
            string str;
            in >> str;
            if (str[0] == 'M') {
                cnt[0]++;
            } else if (str[0] == 'A') {
                cnt[1]++;
            } else if (str[0] == 'R') {
                cnt[2]++;
            } else if (str[0] == 'C') {
                cnt[3]++;
            } else if (str[0] == 'H') {
                cnt[4]++;
            }
            // Count the occurrences of each character at the start of the strings.
        }

        long long res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] +
                        cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] +
                        cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] +
                        cnt[2] * cnt[3] * cnt[4];
        out << res << endl;
        // Calculate the number of combinations and print the result.
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TaskC solver;
    solver.solve(1, cin, cout);
    return 0;
}

// <END-OF-CODE>
