
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cassert>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define LSOne(S) (S & (-S))
#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define FORB(X,Y) for (int (X) = (Y);(X) >= 0;--(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define REPB(X,Y,Z) for (int (X) = (Y);(X) >= (Z);--(X))
#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T max(T a, T b) { return a > b ? a : b; }
template <class T> T min(T a, T b) { return a < b ? a : b; }
template <class T> void chk_Max(T &a, T b) { if (a < b) a = b; }
template <class T> void chk_Min(T &a, T b) { if (a > b) a = b; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; for (int i = 0; i < v.size(); ++i) { if (i) os << ", "; os << v[i]; } os << "}"; return os; }

class InputReader {
    public:
        InputReader(istream& stream) : _stream(stream) {
            _line.reserve(256);
        }

        string next() {
            if (_line.empty()) {
                _stream >> _line;
            }

            string token;

            while (true) {
                if (_line.empty()) {
                    _stream >> _line;
                }

                size_t start = _line.find_first_not_of(" \t\r\n");

                if (start == string::npos) {
                    _line.clear();
                    continue;
                }

                size_t end = _line.find_first_of(" \t\r\n", start);

                if (end == string::npos) {
                    token = _line.substr(start);
                    _line.clear();
                } else {
                    token = _line.substr(start, end - start);
                    _line.erase(0, end);
                }

                return token;
            }
        }

    private:
        istream& _stream;
        string _line;
};

class TaskD {
    public:
        void solve(int testNumber, InputReader in, ostream& out) {
            string S;
            int score = 0;

            S = in.next();

            for (int i = 0; i < S.length(); i++) {
                char my;
                char his;

                my = i % 2 == 0 ? 'g' : 'p';

                his = S.charAt(i);

                if (my != his) {
                    score += my == 'p' ? 1 : -1;
                }
            }

            out << score << endl;
        }
};

int main() {
    InputReader in(cin);
    TaskD solver;
    solver.solve(1, in, cout);
    return 0;
}

