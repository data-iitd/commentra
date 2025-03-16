
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, string s, stringstream& out) {
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
                    if (!d.empty()) {
                        d.pop_back();
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
    stringstream out;
    BUnhappyHackingABCEdit solver;
    solver.solve(1, s, out);
    cout << out.str();
    return 0;
}

// END-OF-CODE