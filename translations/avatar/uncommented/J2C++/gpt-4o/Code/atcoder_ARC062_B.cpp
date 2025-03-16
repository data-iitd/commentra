#include <iostream>
#include <string>

using namespace std;

class TaskD {
public:
    void solve(int testNumber) {
        string S;
        cin >> S;
        int score = 0;
        for (int i = 0; i < S.length(); i++) {
            char my = (i % 2 == 0) ? 'g' : 'p';
            char his = S[i];
            if (my != his) {
                score += (my == 'p') ? 1 : -1;
            }
        }
        cout << score << endl;
    }
};

int main() {
    int testNumber = 1;
    TaskD solver;
    solver.solve(testNumber);
    return 0;
}

// <END-OF-CODE>
