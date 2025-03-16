#include <iostream>
using namespace std;

int main() {
    int a, b;
    int ans;

    cin >> a >> b;

    ans = 0;
    if (a >= 13) {
        ans = b;
    } else if (a >= 6) {
        ans = b / 2;
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
