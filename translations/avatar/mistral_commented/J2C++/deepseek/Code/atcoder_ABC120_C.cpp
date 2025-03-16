#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class TaskB {
public:
    void solve(int testNumber, InputReader& in, ostream& out) {
        string x;
        stack<char> s;
        int c = 0;

        x = in.next();
        for (int i = 0; i < x.length(); i++) {
            s.push(x[i]);

            while (s.size() > 1) {
                char p = s.top();
                s.pop();
                char q = s.top();
                s.pop();

                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    c++;
                    continue;
                }

                s.push(q);
                s.push(p);
                break;
            }
        }

        out << c * 2 << endl;
    }
};

class InputReader {
public:
    InputReader(istream& stream) : istream(stream) {}

    string next() {
        string line;
        if (getline(istream, line)) {
            stringstream ss(line);
            string token;
            while (ss >> token) {
                return token;
            }
        }
        return "";
    }

private:
    istream& istream;
};

int main() {
    InputReader in(cin);
    TaskB solver;
    solver.solve(1, in, cout);
    return 0;
}

