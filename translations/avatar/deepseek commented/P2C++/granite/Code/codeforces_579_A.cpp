

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 1;
    while (log2(n) % 1) {
        x++;
        n -= pow(2, int(log2(n)));
    }
    cout << x << endl;
    return 0;
}
