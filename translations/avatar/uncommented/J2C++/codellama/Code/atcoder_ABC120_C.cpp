
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class InputReader {
public:
    InputReader(istream& stream) : reader(stream) {
        tokenizer = nullptr;
    }
    string next() {
        while (tokenizer == nullptr || !tokenizer->hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer->nextToken();
    }
private:
    istream& reader;
    StringTokenizer* tokenizer;
};

class TaskB {
public:
    void solve(int testNumber, InputReader& in, ostream& out) {
        string x = in.next();
        stack<char> s;
        int c = 0;
        for (int i = 0; i < x.length(); i++) {
            s.push(x[i]);
            while (s.size() > 1) {
                char p = s.top();
                s.pop();
                char q = s.top();
                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    c++;
                    continue;
                } else {
                    s.push(q);
                    s.push(p);
                    break;
                }
            }
        }
        out << c * 2 << endl;
    }
};

int main() {
    InputReader in(cin);
    TaskB solver;
    solver.solve(1, in, cout);
    return 0;
}

