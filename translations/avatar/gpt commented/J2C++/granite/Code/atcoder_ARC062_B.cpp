
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class InputReader {
public:
    InputReader(string s) {
        this->s = s;
        this->pos = 0;
    }

    string next() {
        string res = "";
        while (pos < s.length() && s[pos]!='') {
            res += s[pos];
            pos++;
        }
        pos++;
        return res;
    }

private:
    string s;
    int pos;
};

class TaskD {
public:
    void solve(int testNumber, InputReader in, ostream& out) {
        string s = in.next();
        int score = 0;
        for (int i = 0; i < s.length(); i++) {
            char my = (i % 2 == 0)? 'g' : 'p';
            char his = s[i];
            if (my!= his) {
                score += (my == 'p')? 1 : -1;
            }
        }
        out << score << endl;
    }
};

int main() {
    string s;
    getline(cin, s);
    InputReader in(s);
    TaskD solver;
    solver.solve(1, in, cout);
    return 0;
}

