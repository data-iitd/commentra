#include <iostream>
#include <string>

using namespace std;

class AStationAndBus {
public:
    void solve(int testNumber) {
        string s;
        cin >> s;
        if (s.find('A') != string::npos && s.find('B') != string::npos) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
};

int main() {
    AStationAndBus solver;
    solver.solve(1);
    return 0;
}

// <END-OF-CODE>
