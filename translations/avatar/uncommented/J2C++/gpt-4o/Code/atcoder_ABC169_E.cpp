#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    const int num = 998244353;
    int n;
    cin >> n;
    vector<int> ai(n), bi(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ai[i] >> bi[i];
    }
    
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());
    
    if (n % 2 == 1) {
        cout << bi[n / 2] - ai[n / 2] + 1 << endl;
    } else {
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        cout << static_cast<int>(2 * (c - b) + 1) << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
