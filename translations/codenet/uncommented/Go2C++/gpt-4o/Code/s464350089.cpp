#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int main() {
    int h, n;
    cin >> h >> n;
    int a = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += x;
    }

    if (h > a) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

// <END-OF-CODE>
