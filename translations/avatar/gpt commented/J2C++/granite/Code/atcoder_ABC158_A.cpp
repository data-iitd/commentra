
#include <iostream>
#include <string>

using namespace std;

class AStationAndBus {
public:
    void solve(int testNumber, string s) {
        if (s.find("A")!= string::npos && s.find("B")!= string::npos) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
};

int main() {
    string s;
    cin >> s;
    AStationAndBus solver;
    solver.solve(1, s);
    return 0;
}

