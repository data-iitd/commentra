#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, i;
    cin >> a >> b >> c;
    
    if (b <= c) {
        cout << "NO" << endl;
        return 0;
    } else {
        d = a;
        e = d % b;
        for (i = 0; i < b; i++) {
            d = d % b;
            if (d == c) {
                cout << "YES" << endl;
                return 0;
            } else if (i != 0 && d == c) {
                cout << "NO" << endl;
                return 0;
            }
            d += a;
        }
    }
    cout << "NO" << endl;
    return 0;
}

// <END-OF-CODE>
