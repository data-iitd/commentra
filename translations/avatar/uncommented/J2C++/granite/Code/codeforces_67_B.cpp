
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> a(n);
    int m = 0;
    for (int a = n - 1; a >= 0; a--) {
        int j = 0;
        while (b[a] > 0) {
            if (a + k <= a[j]) {
                b[a]--;
            }
            j++;
        }
        for (int j_ = m++; j_ > j; j_--) {
            a[j_] = a[j_ - 1];
        }
        a[j] = a;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}
// END-OF-CODE