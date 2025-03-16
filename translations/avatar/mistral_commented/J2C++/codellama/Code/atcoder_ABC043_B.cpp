
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class LightScanner {
    private:
        stringstream ss;
        string line;
        vector<string> tokens;

    public:
        LightScanner(string s) {
            ss << s;
        }

        string string() {
            if (tokens.size() == 0) {
                getline(ss, line);
                stringstream lineStream(line);
                string token;
                while (getline(lineStream, token, ' ')) {
                    tokens.push_back(token);
                }
            }
            string token = tokens[0];
            tokens.erase(tokens.begin());
            return token;
        }
};

class BUnhappyHackingABCEdit {
    public:
        void solve(int testNumber, LightScanner in, ostream& out) {
            string s = in.string();
            string d = "";

            for (char c : s) {
                switch (c) {
                    case '0':
                        d += "0";
                        break;
                    case '1':
                        d += "1";
                        break;
                    case 'B':
                        if (d.length() > 0) {
                            d.erase(d.length() - 1);
                        }
                        break;
                }
            }

            out << d << endl;
        }
};

int main() {
    string s;
    getline(cin, s);
    LightScanner in(s);
    BUnhappyHackingABCEdit solver;
    solver.solve(1, in, cout);
    return 0;
}

