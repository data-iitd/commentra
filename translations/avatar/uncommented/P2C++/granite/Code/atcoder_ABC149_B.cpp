
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int leftOver = a - c;
    int takahashi = max(0, leftOver);
    cout << takahashi << " " << (b - abs(leftOver)) << endl;
    return 0;
}
// END-OF-CODE