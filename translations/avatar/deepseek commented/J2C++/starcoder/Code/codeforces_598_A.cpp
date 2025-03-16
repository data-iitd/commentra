#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q-- > 0) {
        int n;
        cin >> n;
        int x = (int)log2(n);
        x++;
        long s = -1 * pow(2, x) + 2 + (n * (n + 1)) / 2 - pow(2, x);
        cout << s << endl;
    }
    return 0;
}

