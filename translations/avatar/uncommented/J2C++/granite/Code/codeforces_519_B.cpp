
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1), c(n-2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n-2; i++) {
        cin >> c[i];
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x += a[i];
    }
    for (int i = 0; i < n-1; i++) {
        y += b[i];
    }
    x -= y;
    for (int i = 0; i < n-2; i++) {
        y += c[i];
    }
    y -= x;
    cout << x << endl;
    cout << y << endl;
    return 0;
}
// END-OF-CODE