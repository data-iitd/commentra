#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Main {
public:
    long long A, B, K;
    long long x, y;

    Main(istream& in) {
        string line;
        getline(in, line);
        stringstream ss(line);
        ss >> A >> B >> K;
    }

    void calc() {
        x = A;
        y = B;
        x = A - K;
        if (x < 0) {
            y = B + x;
            x = 0;
            if (y < 0) {
                y = 0;
            }
        }
    }

    void showResult() {
        cout << x << " " << y << endl;
    }
};

int main() {
    Main ins(cin);
    ins.calc();
    ins.showResult();
    return 0;
}

