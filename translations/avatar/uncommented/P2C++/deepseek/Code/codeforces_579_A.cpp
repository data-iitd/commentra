#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 1;
    while (fmod(log2(n), 1) != 0) {
        x += 1;
        n -= pow(2, static_cast<int>(log2(n)));
    }
    cout << x << endl;
    return 0;
}

