
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r, D, x;
    cin >> r >> D >> x;

    for (int i = 2; i < 12; i++) {
        cout << int(round((pow(r, i - 1) * (x + D / (1 - r))) - D / (1 - r))) << endl;
    }

    return 0;
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)