#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CColoringColorfully {
public:
    void solve(int testNumber) {
        string x;
        cin >> x;
        string a = x;
        string b = x;
        int a1 = 0, a2 = 0;

        for (size_t i = 1; i < x.length(); i++) {
            if (a[i] == a[i - 1]) {
                a[i] = (a[i] == '1') ? '0' : '1';
                a1++;
            }
        }

        for (size_t i = x.length() - 1; i > 0; i--) {
            if (b[i] == b[i - 1]) {
                b[i - 1] = (b[i - 1] == '1') ? '0' : '1';
                a2++;
            }
        }

        cout << min(a1, a2) << endl;
    }
};

int main() {
    int testNumber = 1; // Assuming a single test case as in the Java code
    CColoringColorfully solver;
    solver.solve(testNumber);
    return 0;
}

// <END-OF-CODE>
