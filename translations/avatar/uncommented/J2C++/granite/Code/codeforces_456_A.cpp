
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int max_a = *max_element(a.begin(), a.end());
    int min_a = *min_element(a.begin(), a.end());
    int max_b = *max_element(b.begin(), b.end());
    int min_b = *min_element(b.begin(), b.end());
    if (max_a > min_a && max_b > min_b) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }
    return 0;
}
//END-OF-CODE