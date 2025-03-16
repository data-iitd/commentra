#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << " " << endl;
    int m = n;
    for (int i = n - 1; i > 0; i--) {
        if (m % i == 0) {
            cout << i << " " << endl;
            m = i;
        }
    }
    return 0;
}

// <END-OF-CODE>
