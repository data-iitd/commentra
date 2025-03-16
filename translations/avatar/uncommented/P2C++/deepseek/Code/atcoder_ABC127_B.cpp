#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r, D, x;
    cin >> r >> D >> x;
    for (int i = 2; i <= 11; i++) {
        int result = static_cast<int>(pow(r, i - 1) * (x + D / (1 - r)) - D / (1 - r));
        cout << result << endl;
    }
    return 0;
}

