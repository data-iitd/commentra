#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (accumulate(a.begin(), a.end(), 0) % (n * (n + 1) / 2)) {
        cout << "NO" << endl;
    } else {
        double k = accumulate(a.begin(), a.end(), 0) / (n * (n + 1) / 2);
        a.push_back(a[0]);
        
        int sum1 = 0;
        int sum2 = 0;
        for (size_t i = 1; i < a.size(); ++i) {
            int i_val = a[i];
            int j_val = a[i - 1];
            sum1 += (k - i_val + j_val) % n;
            sum2 += (k - i_val + j_val) / n >= 0;
        }

        if (sum1 != 0 || sum2 != n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
