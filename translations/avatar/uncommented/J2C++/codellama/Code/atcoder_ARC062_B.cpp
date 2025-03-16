
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
using namespace std;

class InputReader {
public:
    InputReader(istream& stream) : m_stream(stream) {
        m_buffer.reserve(32768);
    }

    string next() {
        while (!m_stream.eof()) {
            string line;
            getline(m_stream, line);
            m_buffer += line;
            if (m_buffer.size() > 0 && m_buffer[m_buffer.size() - 1] == '\n') {
                string ret = m_buffer.substr(0, m_buffer.size() - 1);
                m_buffer.erase(0, m_buffer.size());
                return ret;
            }
        }
        return "";
    }

private:
    istream& m_stream;
    string m_buffer;
};

class TaskD {
public:
    void solve(int testNumber, InputReader& in, ostream& out) {
        string S = in.next();
        int score = 0;
        for (int i = 0; i < S.length(); i++) {
            char my = i % 2 == 0 ? 'g' : 'p';
            char his = S[i];
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

