#include <iostream>
using namespace std;

int main() {
    long long k;
    cin >> k;
    long long t = 0;
    
    for (int i = 1; i <= k; ++i) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            cout << i << endl;
            break;
        }
    }
    
    if (t % k != 0) {
        cout << -1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
