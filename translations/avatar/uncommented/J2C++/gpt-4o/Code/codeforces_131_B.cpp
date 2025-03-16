#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    const int N = 1e5 + 5;
    vector<long> cnt(21, 0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x + 10]++;
    }
    
    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    
    cout << res << endl;
    return 0;
}

// <END-OF-CODE>
