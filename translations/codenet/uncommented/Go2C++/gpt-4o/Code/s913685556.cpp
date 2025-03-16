#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    cout << mx << endl;

    return 0;
}

// <END-OF-CODE>
