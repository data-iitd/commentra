#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    if (6 <= A && A <= 12) {
        ans = B / 2;
    } else if (A > 12) {
        ans = B;
    }
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
