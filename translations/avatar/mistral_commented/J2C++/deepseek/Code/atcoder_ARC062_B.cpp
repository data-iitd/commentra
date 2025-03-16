#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class InputReader {
public:
    InputReader() : buffer(new stringstream()) {}
    ~InputReader() { delete buffer; }

    string next() {
        string line;
        if (getline(*buffer, line)) {
            buffer->str(line);
            buffer->clear();
        }
        string token;
        *buffer >> token;
        return token;
    }

private:
    stringstream* buffer;
};

class TaskD {
public:
    void solve(int testNumber, InputReader& in, ostream& out) {
        string S;
        int score = 0;

        S = in.next();

        for (size_t i = 0; i < S.length(); i++) {
            char my;
            char his;

            my = i % 2 == 0 ? 'g' : 'p';

            his = S[i];

            if (my != his) {
                score += my == 'p' ? 1 : -1;
            }
        }

        out << score << endl;
    }
};

int main() {
    InputReader in;
    TaskD solver;
    solver.solve(1, in, cout);
    return 0;
}

